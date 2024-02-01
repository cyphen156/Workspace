function initMenu(n1,n2,n3,n4,n5){  
	//alert(n1);
    $('#pbInitNo1').val(n1);
	$('#pbInitNo2').val(n2);
	$('#pbInitNo3').val(n3);
	$('#pbInitNo4').val(n4);
    $('#pbInitNo5').val(n5);

    var n1 = n1-1;	//$('#gnb'+n1);   // //
    var n2 = n2-1;
    var n3 = n3-1;
    var n4 = n4-1;
    var n5 = n5-1;
    var page = (n1 < 0) ? "main" : "sub";

    //wrap
    var $wrap = $("#wrap");

    //gnb 정보
    var $gnb = $("#gnb");

    //해당 뎁스의 gnb정보
    var gnbData = gnbDataPush($gnb);
    var depth2Data = getNavi([n1]);
    var depth3Data = getNavi([n1,n2]);
    var depth4Data = getNavi([n1,n2,n3]);
    var depth5Data = getNavi([n1,n2,n3,n4]);
    //현재위치
    var nowGnbData = getNavi([n1,n2,n3,n4,n5],true);

    //반응형 체크
    var defWidth = 800;
    var mobileChk = ($wrap.width() < defWidth) ? true : false;

    //선언
    var $gnbList = $gnb.children();
    var $gnbBg = $("#submenuArea");
    var $gnbListFirst = $gnbList.eq(0).children("a");
    var $gnbListLast = $gnbList.eq($gnbList.length-3); //회원정보, 이용안내 제외
    var $mobileOpen = $("#mobileIndexOpen");
    var $mobileClose = $("#mobileIndexClose a");
    var $siteMenu = $("#siteMenu");
    var $libraryShortcut = $("#libraryShortcut");
    var $tab = "";
    var $naviTit = $(".sec_page_tit h3.tit_blk");
    var tabNumChk = 0;
    var mobileGnbTimer = 0;
    var resizeTimer2 = 0;
    var docTitle = document.title;
    var $btnTotal = $(".btnTotal > a");
    var $snsBtn = $(".snsBtn");

    //*** 레이아웃 설정 시작 ***//
    //모바일 메뉴 생성
    if(mobileChk){
        resizeTimer2 = 1;
        gnbMobile($gnb);
    }else{
        resizeTimer2 = 2;
        gnbPc($gnb);
		
    }
    //메인페이지
    if(page == "main"){

    }
    //서브페이지
    else{

        //타이틀 태그 변경
        nowPageTit({
            "basicTit" : docTitle //기본 출력되는 이름
        });

        //현재 GNB에 클래스 부여
        if(n1 >= 0) gnbData[n1]["obj"].parent().addClass("on");
        if(n2 >= 0) depth2Data[n2]["obj"].addClass("on"); //lnb on
        if(n3 >= 0) depth3Data[n3]["obj"].addClass("current"); //lnb on depth

        //서브 타이틀
        $naviTit.text(nowGnbData["text"]);

        //네비게이션
        $naviTit.parent().siblings(".sec_page_location").html(navi({
            "homeIcon" : "<img src='/goe_jsp/resource/images/ico_home.png' alt='홈' />",
            "hideTemplate" : ["<ul>","</ul>"],
            "nowCont" : ["<strong>","</strong>"]
        }));

		//if(!mobileChk){

            //LNB 생성
            $("#lnbNav > h2").html(gnbData[n1]["obj"].html());
            //2뎁스, 하위메뉴 출력
            $("#lnb").html(makeList(depth2Data,false,n2,n3));


        //}

			

        //MkTab class를 가지고 있다면 탭 생성
        if(nowGnbData["class"] && nowGnbData["class"].indexOf("MkTab") > -1){
            var tabData = "";
            if(depth5Data){
                tabData = depth5Data;
            }else if(depth4Data){
                tabData = depth4Data;
            }else if(depth3Data){
                tabData = depth3Data;
            }else{
                console.log("잘못된 탭 생성입니다.");
            }
            makeTab({
                "tabData" : tabData,
                "$tabWrap" : $(".tabNav"),
                "$tab" : $(".tnb")
            });
        } else {
			$(".tabNav").addClass('hide');
		}
		
		//-- 탭생성 끝 --//


		




        //사이트맵 추가
        $("#sitemap").html(makeList(gnbData,true,n1,n2,n3));

        //게시판 caption 추가
        //주소에 bbsList.do, bbsList.do, bbsWrite.do (게시판) 일 경우
        var thisHref = location.href;
        if(thisHref.indexOf("bbsPostList.do") >= 0 || thisHref.indexOf("bbsPostDetail.do") >= 0 || thisHref.indexOf("bbsPostRegist.do") >= 0 || thisHref.indexOf("bbsPostUpdate.do") >= 0){
            captionOverWrite(thisHref);
        }

        function captionOverWrite(href){
            //게시판 테이블이 board-list, board-view class를 가지기 때문에 이걸로 구분
            $("table").each(function(){
                var $this = $(this);
                var $iR = $this.find("td.content").find("img");
                if($iR.attr("alt") >= 0){
                   $iR.attr("alt","하단내용참조");
                }
                //board를 포함하는 table이라면 caption 추가
                if($this.attr("class") && $this.attr("class").indexOf("board") >= 0){
                    var $caption = $this.find("caption");
                    var str = "";
                    $this.find("th").each(function(e){
                        if(e != 0) str += ", ";
                        str += $(this).text();
                    });
                    var str_strong,str_p;
                    if(href.indexOf("bbsPostList.do") >= 0){
                        str_strong = nowGnbData["text"] + " 게시글 목록";
                        str_p = str + " 제공 표";
                    }else if(href.indexOf("bbsPostDetail.do") >= 0){
                        str_strong = nowGnbData["text"] + " 게시글 상세정보";
                        str_p = str + " 제공 표";
                    }else if(href.indexOf("bbsPostRegist.do") >= 0){
                        str_strong = nowGnbData["text"] + " 입력 양식";
                        str_p = nowGnbData["text"] + " 게시판의 글 쓰기 내용을 " + str + "의 항목별로 해당하는 내용을 필수항목과 선택항목으로 구분하여 입력 가능합니다.";
                    }else if(href.indexOf("bbsPostUpdate.do") >= 0){
                        str_strong = nowGnbData["text"] + " 양식 수정";
                        str_p = nowGnbData["text"] + " 게시판의 글 쓰기 내용을 " + str + "의 항목별로 해당하는 이미 입력된 내용을 수정 할 수 있습니다.";
                    }
                    $caption.html("");
                    $caption.append("<strong>" + str_strong + "</strong>");
                    $caption.append("<p>" + str_p + "</p>");
                }
            });
        }

       

    } //-- 서브 끝 --//

    //** 메인,서브 공통 시작 **//

    //페이지 상관없이 탭 사용 할 수 있게끔
    if(!nowGnbData["class"] || nowGnbData["class"].indexOf("MkTab") < 0){
        $(".tabNav").each(function(){
            var $this = $(this);
            var $tab = $this.children(".tnb");
            var $tabList = $tab.children();
            if($tabList.size() > 1){
                $this.show();
                tabChange($tab,mobileChk);
                tabNumChk = 1;
            }
        });
    }

    //--- 레이아웃 설정 끝 ---//

    //** 이벤트 등록 시작 **//
	//gnb 마우스 오버/포커스 이벤트
    function gnbPc($gnb){

    }

    //모바일 메뉴 2,3뎁스 열기/닫기 이벤트를 위한 링크 정리, 이벤트 등록
    function gnbMobile($mobileGnb){

    }
    //-- 이벤트 등록 끝 --//

    //탭 생성
    function makeTab(obj){
        var $tabWrap = obj["$tabWrap"];
        $tab = obj["$tab"];
        var obj = obj["tabData"];
        var tab = "";
        var tabLength = obj.length;
        for(var i=0;i<tabLength;i++){
            var tag = obj[i]["obj"];
            if(nowGnbData["obj"][0].outerHTML == tag[0].outerHTML){
                (i == tabLength - 1) ? tab += "<li class='on'>" : tab += "<li class='on'>";
            }else{
                (i == tabLength - 1) ? tab += "<li class=''>" : tab += "<li>";
            }
            tab += tag[0].outerHTML + "</li>\n";
        }
		

        //console.log(tab);
		$tabWrap.addClass('ty_0'+tabLength);
        $tab.html(tab);
        $tabWrap.show();
    }

    //depthData에 따른 리스트 출력, chk로 하위 뎁스 전체 보임 여부, chkNum와 chkNum2,chkNum3로 현재위치 지정
    function makeList(depthData,chk,chkNum,chkNum2,chkNum3){
        var list = "";
        var lnbLength = depthData.length;
        for(var i=0;i<lnbLength;i++){
            var tag = depthData[i]["obj"].clone();
            list += "<li>" + tag[0].outerHTML;
			var keyLength = 0;
			var childDepth = depthData[i]["childDepth"];
			if(childDepth.length >= 1 && ((childDepth[0] && childDepth[0]["class"] == "MkSub") || chk) && chk != "nav"){
                if(chkNum == i || chk){
                    list += "\n<ul class='depth'>\n";
					//alert('aaa');
                }else{
                    list += "\n<ul class='depth' style='display:none;'>\n";
					//alert('aaa');
                }
                var depthDownDataLength = childDepth.length;
                for(var j=0;j<depthDownDataLength;j++){
                    var tag2 = childDepth[j]["obj"].clone();
                    list += "<li>" + tag2[0].outerHTML;
                    if(chkNum3){
                        var keyLength2 = 0;
                        var childDepth2 = childDepth[j]["childDepth"];
                        for(var name in childDepth2){ keyLength2++; }
                        if(keyLength2 > 1 && ((childDepth[0] && childDepth[0]["class"] == "MkSub") || chk)){
                            if(chkNum2 == j || chk){
                                list += "\n<ul>\n";
                            }else{
                                list += "\n<ul style='display:none;'>\n";
                            }
                            var depthDownDataLength2 = childDepth2.length;
                            for(var k=0;k<depthDownDataLength2;k++){
                                var tag3 = childDepth2[k]["obj"].clone();
                                list += "<li>" + tag3[0].outerHTML + "</li>\n";
                            }

                            list += "</ul>\n";
                        }
                    }
                    list += "</li>\n";
                }
                list += "</ul>\n";
            }
            list += "</li>\n";
        }

        //console.log(list);
        return list;
    }

    //타이틀 변경 주소 지정값이 있을 경우엔 해당하는걸로 아니면 현재 페이지 이름
    function nowPageTit(obj){
        var nowUrl = location.href;
        var basicTit = obj["basicTit"];
        document.title = nowGnbData["text"] + " : " + basicTit; // title
        for(var url in obj){
            if(nowUrl.indexOf(url) > -1){
                document.title = obj[url] + " : " + basicTit;
                return false;
            }
        }
        return false;
    }

    //서브타이틀 하단 네비게이션 출력
    function navi(obj){
        var homeIcon = obj["homeIcon"];
        var hideTemplate = obj["hideTemplate"];
        var nowCont = obj["nowCont"];
        var num = 0;
        var pageNum = [n1,n2,n3,n4,n5];
        var str = [];
        var result = "";
        var length = pageNum.length;
        for(var i=0;i<length;i++){
            if(pageNum[i] >= 0){
                switch(i){
                    case 0 : str[num] = gnbData[pageNum[i]]["obj"].html(); break;
                    case 1 : str[num] = depth2Data[pageNum[i]]["obj"].html(); break;
                    case 2 : str[num] = depth3Data[pageNum[i]]["obj"].html(); break;
                    case 3 : str[num] = depth4Data[pageNum[i]]["obj"].html(); break;
                    case 4 : str[num] = depth5Data[pageNum[i]]["obj"].html(); break;
                }
                num++;
            }else{
                break;
            }
        }
        result += "<span>" + homeIcon +  "</span>" ;
        str[num-1] = nowCont[0] + str[num-1] + nowCont[1];
        result += hideTemplate[0];
        for(var j=0;j<num;j++){
            result += "<li>" + str[j] + "</li>";
        }
        result += hideTemplate[1];

        return result;
    }

	


    //gnb 정보 저장
    function gnbDataPush(obj){
        var depthChk = 0;
        var depthData = [];
        var depth = obj.children();
        dataPush(depth, depthData);
        function dataPush(depth, depthData){
            var length = depth.length;
            for(var i=0;i<length;i++){
                var $this = depth.eq(i).children("a");
                depthData[i] = data($this);
                var downDepth = $this.siblings().children();
                if(downDepth.length > 0){
                    dataPush(downDepth, depthData[i]["childDepth"]);
                }
            }
        }
        function data($this){
            return {
                "obj" : $this,
                "text" : $this.text(),
                "href" : $this.attr("href"),
                "class" : $this.parent().parent().attr("class"), //MkTab인지 구분
                "childDepth" : []
            };
        }
        return depthData;
    }

    //해당하는 네비게이션 정보 추출
    //array = 페이지번호, nowChk = 현재위치가 필요한지 체크
    function getNavi(array, nowChk){
        var data = gnbData;
        var length = array.length;
        var num = 0;
        for(var i=0;i<length;i++){
            if(array[i] >= 0){
                if(nowChk){
                    data = (array[i+1] >= 0) ? data[array[i]]["childDepth"] : data[array[i]];
                }else{
                    data = data[array[i]]["childDepth"];
                }
            }else{
                break;
            }
        }
        if(!nowChk && data.length < 1){
            //console.log("해당하는 " + (length+1) + "뎁스가 없습니다.");
            return false;
        }
        return data;
    }
}



window.onresize = function() {

}