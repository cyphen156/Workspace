/*/////////////////////////////////////////////
//! contents - jQuery						///
//! 2019-12-03								///
//! 김형윤 / unida1220@naver.com				///
/////////////////////////////////////////////*/

//---------------------------------------------------------------------------------------------------
//  print 설정
//---------------------------------------------------------------------------------------------------
function fnPrintPopup() {
	var win = window.open( "/goe_jsp/inc/printPop.jsp", "popup_print", "width=763,height=500, scrollbars=yes");
	win.focus();
}





$( document ).ready( function() {

//---------------------------------------------------------------------------------------------------
//  navigator 활용해 접속 디바이스 check 설정
//---------------------------------------------------------------------------------------------------
	function browser_chk() {
		var filter = "win16|win32|win64|mac|macintel";
		if ( navigator.platform ) {
			if ( filter.indexOf( navigator.platform.toLowerCase() ) < 0 ) { //mobile

			} else { //pc

			}
		}
	}


//---------------------------------------------------------------------------------------------------
//  main NOTICE 설정
//---------------------------------------------------------------------------------------------------
	var popup_h = $("#wrap_popup").height() + 1;
	function getCookie(cname) {
		var name = cname + "=";
		var ca = document.cookie.split(';');
		for(var i=0; i<ca.length; i++) {
			var c = ca[i];
			while (c.charAt(0)==' ') c = c.substring(1);
			if (c.indexOf(name) != -1) return c.substring(name.length,c.length);
		}
		return "";
	}
	function setCookie(cname, cvalue, exdays) {
		var d = new Date();
		d.setTime(d.getTime() + (exdays*24*60*60*1000));
		var expires = "expires="+d.toUTCString();
		document.cookie = cname + "=" + cvalue + "; " + expires;
	}

	/* setcookie */
	function todayClose(){
		if($("input[name='close_today']").is(":checked") ==true){
			setCookie("todayClose","Y",1);
		}
		$("#wrap_popup").slideUp(200);
	}

	function notice_popup() {

		var docTop = $("#wrap_header").offset();
		$(window).scroll(function(){
			var docScrollY = $(document).scrollTop();
			var wrapHeader = $("#wrap_header");
			var wrapCont = $("#wrap_cont");
			if( docScrollY > docTop.top ) {
				wrapHeader.addClass("wrapHfixed");
				wrapCont.addClass("wrapContPT");
			}else{
				wrapHeader.removeClass("wrapHfixed");
				wrapCont.removeClass("wrapContPT");
			}
		});

		$(document).ready(function(){
			cookiedata = document.cookie;
			if ($("#wrap_popup").hasClass("active")) {
			}

			if(cookiedata.indexOf("todayClose=Y") < 0){
			}else{
				$("#wrap_popup").removeClass('active').hide();
			}
			$("#wrap_popup .close").click(function(){
				todayClose();
				$("#wrap_header").css("position","fixed").animate({top: 0 }, 200);
				$("#wrap_cont").css("padding-top",191 + popup_h).animate({paddingTop: 191 }, 200);
				$("#wrap_popup").removeClass('active').hide();
			});

		});
	}

	function notice_popup_mobile() {

		var docTop = $("#wrap_header").offset();
		$(window).scroll(function(){
			var docScrollY = $(document).scrollTop();
			var wrapHeader = $("#wrap_header");
			var wrapCont = $("#wrap_cont");
			if( docScrollY > docTop.top ) {
				wrapHeader.addClass("wrapHfixed");
				wrapCont.addClass("wrapContPT");
			}else{
				wrapHeader.removeClass("wrapHfixed");
				wrapCont.removeClass("wrapContPT");
			}
		});

		$(document).ready(function(){
			cookiedata = document.cookie;
			if ($("#wrap_popup").hasClass("active")) {
			}

			if(cookiedata.indexOf("todayClose=Y") < 0){
			}else{
				$("#wrap_popup").removeClass('active').hide();
			}
			$("#wrap_popup .close").click(function(){
				todayClose();
				$("#wrap_header").css("position","fixed").animate({top: 0 }, 200);
				$("#wrap_cont").css("padding-top",112 + popup_h).animate({paddingTop: 112 }, 200);
				$("#wrap_popup").removeClass('active').hide();
			});

		});

	}





//---------------------------------------------------------------------------------------------------
//  main 게시판 탭 설정
//---------------------------------------------------------------------------------------------------
	function notice_tab() {
		$(".goe_notice_blk .infor_blk .tab_blk").addClass("line");
		$(".goe_notice_blk .tab_blk >a").off().on("click, focus", function(e) {
			//alert('a');
			e.preventDefault();
			$(".goe_notice_blk .list_cont_blk, .goe_notice_blk .btn_more").hide();
			$(".goe_notice_blk .tab_blk").removeClass("line");
			$(".goe_notice_blk .tab_blk >a").removeClass("on");
			$(this).addClass("on");
			$(this).parent().next().css("display", "block").next().css("display", "block");

			if ($(".goe_notice_blk .notice_blk .tab_blk >a").hasClass("on")) {
				$(".goe_notice_blk .infor_blk .tab_blk").addClass("line");
			} else if ($(".goe_notice_blk .infor_blk .tab_blk >a").hasClass("on")) {
				$(".goe_notice_blk .announce_blk .tab_blk").addClass("line")
			}
		});
	}


//---------------------------------------------------------------------------------------------------
//  footer 기관 link 영역 설정
//---------------------------------------------------------------------------------------------------
	function agency_link() {

		$(".sec_direct_link .link_select >a").off().on("click", function() {
			if ($(this).next(".link_list_blk").hasClass('open') == 1) {
				$(".sec_direct_link .link_list_blk").removeClass('open').hide();
			} else {
				$(".sec_direct_link .link_list_blk").removeClass('open').hide();
				$(this).next(".link_list_blk").addClass('open').show ();
			}
		});

		$(".sec_direct_link .link_select").on("mouseleave",function(){
			$(".sec_direct_link .link_list_blk").removeClass('open').hide();
		});

	}



//---------------------------------------------------------------------------------------------------
//  GNB web Ver. 설정
//---------------------------------------------------------------------------------------------------
	function gnb_web() {
		$(".mn_part >.depth").hide();
		$(".sec_gnb").hover(function() {
			$(".bg_gnb").stop(true,true).show();
			$(this).find(".depth").show();
			$(this).find(".mn_part").show();
			$(this).find(".mn_part >.depth").hide();
		}, function() {
			$(".sec_gnb .mn_blk li").removeClass("on");
			$(".bg_gnb, .sec_gnb .mn_blk .mn_part, .sec_gnb .mn_blk .depth").hide();
			$(".mn_part >.depth, .sec_header .btn_mn_close_w").hide();
			$(".sec_header .btn_mn_open").show();
			$(".sec_gnb .mn_blk .depth >li >a.on").parent().parent().parent().addClass("active");
		});
		$(".sec_header .btn_mn_open").on("click",function(){
			$(this).hide();
			$(".sec_header .btn_mn_close_w").show();
			$(".bg_gnb").stop(true,true).show();
			$(".sec_gnb .mn_blk .mn_part, .sec_gnb .mn_blk .depth").show();
			$(".sec_gnb .mn_blk li:first a:first").focus();
			$(".mn_part >.depth").hide();
		});
		$(".sec_header .btn_mn_close_w").on("click",function(){
			$(this).hide();
			$(".sec_header .btn_mn_open").show();
			$(".sec_gnb .mn_blk li").removeClass("on");
			$(".bg_gnb, .sec_gnb .mn_blk .mn_part, .sec_gnb .mn_blk .depth").hide();
			$(".mn_part >.depth").hide();
		});
		$(".sec_gnb .mn_blk .depth a").on("mouseover",function(){
			$(".sec_gnb .mn_blk li").removeClass("on active");
			$(this).parent().parent().parent().addClass("on");
			$(".mn_part >.depth").hide();
		});
		$(".sec_gnb .mn_blk li").on("mouseleave",function(){
			$(this).removeClass("on active");
			$(".mn_part >.depth").hide();

		});

		$(".mn_blk >li >a").bind("click", function(){ // mn click event
			$(this).each(function(){
				$(".mn_blk >li, .sec_gnb .mn_part_tit").removeClass('on');
				$(".mn_blk .depth").show();
				$("#gnb .mn_part").show();
			});
			$(this).parent().addClass('on');
			//$(this).next().show();
		});


		$(".sec_gnb .mn_blk li a").focus(function() { // tab focus
			$(".bg_gnb, .sec_gnb .mn_blk .mn_part, .sec_gnb .mn_blk .depth").show();
			$(".mn_part >.depth").hide();
		});
		$(".sec_gnb .mn_part.p11:last >a").focusout(function () { // tab focus out hide
			if ($(this).has(document.activeElement).length == 0) {
				$(".bg_gnb, .sec_gnb .mn_blk .mn_part, .sec_gnb .mn_blk .depth").hide();
				$(".btn_mn_open").focus();
				$(".mn_part >.depth").hide();
			}
		});
		$(".sec_logbox li:last a").focus(function () { // tab focus out - logbox hide
			$(".bg_gnb, .sec_gnb .mn_blk .mn_part, .sec_gnb .mn_blk .depth").hide();
			$(".mn_part >.depth").hide();
		});
	}


//---------------------------------------------------------------------------------------------------
//  GNB mobile Ver. 설정
//---------------------------------------------------------------------------------------------------
	function gnb_mobile() {
		var mn_blk_h = $(window).height() - 61;
		var part_dep_w = $(window).width() - 120;

		if ($(".mn_blk .depth li > .MkSub").length) {
			$(".mn_blk .depth li > .MkSub").prev().addClass("dep");
		}

		if ($(".mn_part > .depth").length) {
			$(".mn_part > .depth").prev().addClass("dep");
		}

		$(".sec_gnb").unbind("mouseenter mouseleave");

		$(".sec_header .btn_mn_open.gnb_m").off().on("click", function(){
			$(".btn_mn_close_m, .bg_gnb").addClass("on").show();
			$(".sec_gnb, .sec_logbox").show();
			$(".mn_blk >li >.depth").css("height",mn_blk_h).hide().parent().removeClass("on");
			$(".mn_part >.depth").removeClass("open").removeAttr("style"); //.mn_part,
			$(".mn_blk .depth >li").removeClass("current");
			$(".mn_part, .MkSub").removeClass("current").removeAttr("style").hide();
			$("html, body").attr("style","height:"+$(window).height()+"px; width:"+$(window).width()+"px; overflow:hidden");

			$(".mn_blk .depth li .MkSub li a.current").parent().parent().show().parent().addClass("current").parent().show().parent().addClass("on");
			$(".mn_blk .depth li >a.on").parent().parent().show().parent().addClass("on");

			if($("#gnb >li.mn_part").hasClass("on")) {
				$(".mn_part_tit").addClass("on");
				$("#gnb >li.mn_part").addClass("on").css("display","list-item");
				$(".mn_blk").attr("style","overflow-y:scroll; height:"+ mn_blk_h +"px;");
				$(".mn_blk > li.mn_part >.depth li >a.on").parent().parent().show().attr("style","width:"+ part_dep_w +"px !important;").parent().addClass("current").css("display", "inline-block").find(".MkSub").show();
			}
			if($("body").hasClass("main")){
				$(".mn_blk >li#gnb1").addClass("on");
				$(".dep_01").css("display","block");
			}
		});

		$(".sec_gnb .mn_blk .depth a").unbind("mouseover");
		$(".sec_gnb .mn_blk li").unbind("mouseleave");

		$(".mn_blk >li >a").bind("click", function(){ // mn click event

			$(".mn_blk >li, .sec_gnb .mn_part_tit").removeClass('on');
			$(".mn_blk .depth, .mn_blk .depth .MkSub").hide();
			$(".mn_blk .depth >li").removeClass('current');
			$(".mn_blk").removeAttr("style");
			$(".mn_part").removeClass("current").removeAttr("style").hide();
			$(".mn_part >.depth").removeClass("open").removeAttr("style");
			$(this).parent().addClass('on');
			$(this).next().show();
		});

		$(".mn_blk .depth >li >a").off().on("click", function(){ // gnb open
			if($(this).next().css('display') == 'block') {
				$(".mn_blk .depth >li").removeClass('current');
				$(".mn_blk .depth li > .MkSub").hide();
			} else if ($(this).next().css('display') == 'none') {
				$(".mn_blk .depth >li").removeClass('current').find(">a").removeClass("on");
				$(".mn_blk .depth li > .MkSub").hide();
				$(this).parent().addClass('current');
				$(this).next().show();
			}

		});
		$(".btn_mn_close_m").bind("click", function(){ // gnb close
			$(this).removeClass("on").hide();
			$(".bg_gnb, .sec_gnb, .sec_logbox").hide();
			$("html, body").removeAttr("style");
			if($("body").hasClass("main")){
				$(".mn_blk >li#gnb1").removeClass("on");
				$(".dep_01").css("display","none");
			}
		});


		$(".sec_gnb .mn_part_tit").bind("click", function(){ //
			$(".mn_blk >li").removeClass('on');
			$(".mn_blk .depth, .mn_blk .depth .MkSub").hide();
			$(".mn_blk").attr("style","overflow-y:scroll; height:"+ mn_blk_h +"px;");
			$(".mn_part").removeClass("current").removeAttr("style");
			$(".mn_part >.depth").removeClass("open").removeAttr("style").hide();
			$("#gnb .mn_part").addClass('on').show();
			$(this).addClass('on');
		});

		$(".mn_part >a").off().on("click", function(){ //

			if($(this).next().css('display') == 'block') {
				$(".mn_part").removeClass("current").css("display", "list-item");
				$(".mn_part >ul").removeClass("open");
				$(".mn_part .depth >li .MkSub").hide();
			} else if ($(this).next().css('display') == 'none') {
				$(".mn_part").removeClass("current").removeAttr("style");
				$(".mn_part >ul").removeClass("open");
				$("#gnb .mn_part").addClass('on').show();
				$(".mn_part .depth >li .MkSub").show();
				$(".mn_part .depth").attr("style","width:"+ part_dep_w +"px !important;");
				$(this).parent().addClass("current").css("display", "inline-block");
				$(this).next().addClass('open');
			}
		});

		$(".mn_part .depth >li >a").bind("click", function(){
			$(".mn_part .depth >li .MkSub").show();
		});

		$(".mn_part.p06").insertAfter(".mn_part.p05");
	}




//---------------------------------------------------------------------------------------------------
//  only mobile main GNB Ver. 설정
//---------------------------------------------------------------------------------------------------
	function gnb_mobile_main() {
		if ($(".sec_gnb_mobile_main .depth_m li > .dep_list_m").length) {
				$(".sec_gnb_mobile_main .depth_m li > .dep_list_m").prev().addClass("dep");
		}

		$(".sec_gnb_mobile_main .mn_mobile_blk >li >a").off().on("click", function(){ // mn click event
			$(".mn_mobile_blk >li").addClass("line").removeClass("on");
			$(".mn_mobile_blk .depth_m >li").removeClass("current");
			$(".mn_mobile_blk .depth_m, .mn_mobile_blk .depth_m li > .dep_list_m").hide();

			$(this).parent().addClass('on');
			$(".bg_gnb_mobile, .btn_mn_mobile_close_m").show();
			$("html, body").attr("style","height:"+$(window).height()+"px; width:"+$(window).width()+"px; overflow:hidden");
			$(".sec_gnb_mobile_main .depth_m").css('width', $(window).width() - 40 );
			$(".sec_gnb_mobile_main .depth_m").css('height', $(window).height() - 210 );
			$(this).next().show();
		});

		$(".btn_mn_mobile_close_m").off().on("click", function(){ // gnb close
			$(this).hide();
			$("html, body").removeAttr("style");
			$(".mn_mobile_blk li").removeClass("line").removeClass("on");
			$(".bg_gnb_mobile, .sec_gnb_mobile_main .depth_m").hide();

		});

		$(".sec_gnb_mobile_main .depth_m >li >a").off().on("click", function(){ // gnb depth open
			if($(this).next().css('display') == 'block') {
				$(".sec_gnb_mobile_main .depth_m >li").removeClass('current');
				$(".sec_gnb_mobile_main .depth_m li > .dep_list_m").hide();
			} else if ($(this).next().css('display') == 'none') {
				$(".sec_gnb_mobile_main .depth_m >li").removeClass('current');
				$(".sec_gnb_mobile_main .depth_m li > .dep_list_m").hide();
				$(this).parent().addClass('current');
				$(this).next().show();
			}

		});

		
		$(".mn_part.p11").insertAfter(".mn_part.p12");
		$(".mn_part.p10").insertAfter(".mn_part.p12");
	}



//---------------------------------------------------------------------------------------------------
//  LNB 설정
//---------------------------------------------------------------------------------------------------
	function lnbMenu() {
		if($("#lnb >li >.depth").length) {
			$("#lnb >li >.depth").parent().addClass('dep_ico');
		}

		$(".lnb_blk >li.dep_ico >a").click(function(){
			if ($(this).next('.depth').css('display') == 'block') {
				$(this).removeClass("on");
				$(".depth").slideUp();
			} else if ($(this).next('.depth').css('display') == 'none') {
				$(".depth").slideUp();
				$(this).addClass("on");
				$(this).next(".depth").stop(true,true).slideDown();
			}
		});

		$(".depth >li >a").bind("click", function(){
			$(this).each(function(){
				$(".depth >li").removeClass('current');
			});
			$(this).parent().addClass('current');
		});

	}


//---------------------------------------------------------------------------------------------------
//  page SNS Share BTN 설정
//---------------------------------------------------------------------------------------------------
	function sns_share() {

		$(".page_btn_blk .btn_sns_share").off().on("click", function() {
			if ($(".sns_share").hasClass('open') == 1) {
				$(".sns_share").removeClass('open').animate({ opacity: 0, right: "70px" }, 200).hide(50);
			} else {
				$(".sns_share").addClass('open').show(50).animate({ opacity: 1, right: "115px" }, 200);
			}
		});

		//$(".page_btn_blk .sns_share >a").off().on("click", function() {
		//	$(".sns_share").removeClass('open').animate({ opacity: 0, right: "70px" }, 200).hide(50);
		//});


	}




//---------------------------------------------------------------------------------------------------
//  page SNS Share BTN mobile 설정
//---------------------------------------------------------------------------------------------------
	function sns_share_mobile() {
		$(".page_btn_blk .btn_sns_share").off().on("click", function(){
			if ($(".sns_share").css("display") == 'block') {
				$(".sns_share").animate({ opacity: 0, right: "0px" }, 300).hide(0);
			} else if ($(".sns_share").css("display") == 'none') {
				$(".sns_share").show(0).animate({ opacity: 1, right: "35px" }, 300);
			}
		});

	}

//---------------------------------------------------------------------------------------------------
//  search mobile 설정
//---------------------------------------------------------------------------------------------------
	function search_mobile() {
		$(".btn_search_mobile").bind("click", function(){
			$(".sec_search").show();
		});
		$(".btn_search_mobile_close").bind("click", function(){
			$(".sec_search").hide();
		});

	}



//---------------------------------------------------------------------------------------------------
//  sub tab Depth view 설정
//---------------------------------------------------------------------------------------------------

	function tab_toggle_cont() {
		$(".tab_toggle_blk ul li").bind("click", function(){
			var i = $(this).index() + 1;
			//alert(i);
			$(".tab_toggle_blk ul li").removeClass("on");
			$(this).addClass("on");
			$(".tab_toggleCont_blk").removeClass("on").hide();
			$(".tab_toggleCont_blk.cont_0"+i).addClass("on").show();
		});


		$(".sec_tab_dep_blk li").bind("click", function(){
			var i = $(this).index() + 1;
			//alert(i);
			$(".sec_tab_dep_blk li").removeClass("on");
			$(this).addClass("on");
			$(".tab_cont_dep_blk").removeClass("on").hide();
			$(".tab_cont_dep_blk.cont_dep_0"+i).addClass("on").show();
		});


	}




//---------------------------------------------------------------------------------------------------
//  교육비신청 FAQ - qna  영역 설정
//---------------------------------------------------------------------------------------------------
	function qna_cont() {
		$(".sec_qna_blk >.qna_blk >.ques_blk").off().on("click", function() { // 교육비신청 FAQ
			$(".sec_qna_blk >.qna_blk >.answer_blk").slideUp(50);
			$(".sec_qna_blk >.qna_blk").removeClass("on");
			$(this).next().slideDown(100);
			$(this).parent().addClass("on");
		});

		/*
		$(".sec_faq_blk >.faq_blk >.ques_blk").off().on("click", function() { // 공익제보센터 FAQ
			$(".sec_faq_blk >.faq_blk >.answer_blk").slideUp(50);
			$(".sec_faq_blk >.faq_blk").removeClass("on");
			$(this).next().slideDown(100);
			$(this).parent().addClass("on");
			
		
		});

		*/

	}







//---------------------------------------------------------------------------------------------------
//  Tab 5depth select 변경 설정
//---------------------------------------------------------------------------------------------------
	function tab_select() {
		var current = $(".tab_ty_select .go_select .go_tit");
		var list_go = $(".go_list_blk .list_blk li a");
		var select_page_name = $("#select_page_tit").text();
		current.html(select_page_name); // 현재 페이지 name 출력
		current.off().on("click", function(){
			$(this).toggleClass("on");
			$(".go_list_blk").toggle();
		});
		list_go.bind("click", function(){
			current.removeClass("on");
			$(".go_list_blk").hide();
		});
	}




//---------------------------------------------------------------------------------------------------
//  mobile default setting
//---------------------------------------------------------------------------------------------------
	function mobile_setting() {
		$("#gnb >li >a").attr("onclick","return false;");
		$("#gnb >li.mn_part >a").removeAttr("onclick");
		$(".mn_part >.depth >li >.MkSub >li > a.blank").parent().addClass("li_blank");

		$(".sec_gnb, .sec_logbox").hide();
		$(".btn_mn_close_m, .bg_gnb").removeClass("on").hide();
		$("html, body, .sec_gnb, .mn_blk .depth").removeAttr( "style" );

		$(".sec_direct_link").addClass("sec_flex_box");

		var reserve_infor_w = $(window).width() - 255;
		$(".tb_reserve table .infor_02").css("width",reserve_infor_w);

		// 이미지 새창
		var imgView = document.getElementsByClassName("imgView");
		for (var x = 0; x < imgView.length; x++) {
		  imgView.item(x).onclick=function() {window.open(this.src)};
		}

		// 하위 메뉴 click return false
		if($("#gnb .depth >li >ul").hasClass("MkSub")) {
			$("#gnb .depth >li >ul.MkSub").prev().attr("onclick","return false;");
		}

		if($("#gnb >li.mn_part >ul").hasClass("depth")) {
			$("#gnb >li.mn_part >ul.depth").prev().attr("onclick","return false;");
		}

		// 전자민원 경기교육행정서비스 부서별이행기준 부서선택 Tab
		if($("#gnb1_5_3 >a").hasClass("current") == 1) {
			$(".sec_tab_blk").addClass("mb_0");
		}

		// 공익제보센터 Tab Design check
		var tabText = $(".sec_tab_blk .tnb li >a ").text();
		var findStringComp = "부패행위 제보";
		if(tabText.indexOf(findStringComp) != -1) {
			$(".sec_tab_blk").addClass("blk_flex_tab");
			$(".sec_tab_blk .tnb").addClass("tab_ty_report");
		}
		// 통합자료실-과자료실 Tab Design check
		var findStringDepart = "과자료실";
		if(tabText.indexOf(findStringDepart) != -1) {
			$(".sec_tab_blk").addClass("blk_flex_tab");
		}

		if($(".sec_tab_blk").hasClass("blk_flex_tab") == 1) {
			//alert('a');
			$(".sec_tab_blk").parent().css("display","flex");
		}

		// 조직도 부서 cont 매칭 check
		var findStringOrgan = $("#organ_depart_name").html();
		$(".sec_organ_mn_mobile a").removeClass("on").parent().removeClass("on");
		$(".sec_organ_mn_mobile a:contains("+findStringOrgan+"):first").addClass("on").parent(".dep2lst2, strong, dt").addClass("on");


	}


//---------------------------------------------------------------------------------------------------
//  web default setting
//---------------------------------------------------------------------------------------------------
	function web_setting() {

		$("#gnb >li >a, .mn_blk .depth li a").removeAttr("onclick");
		$(".sec_direct_link").removeClass("sec_flex_box");
		$(".btn_mn_close_m").removeClass("on");
		$(".mn_blk .depth li").removeClass("current");
		$(".sec_gnb, .sec_logbox").show();
		$(".btn_mn_close_m, .bg_gnb, .mn_blk .depth li .MkSub").removeClass("on").hide();
		$("html, body, .sec_gnb, .mn_blk,  .mn_blk .depth, .mn_part").removeAttr( "style" );


		// 전자민원 경기교육행정서비스 부서별이행기준 부서선택 Tab
		if($("#gnb1_5_3 >a").hasClass("current") == 1) {
			$(".sec_tab_blk").addClass("mb_0");
		}
		/*var locationText = $(".sec_page_location ul > li ").text();
		var findStringService = "부서별이행기준";
		if(locationText.indexOf(findStringService) != -1) {
			$(".sec_tab_blk").addClass("mb_0");
		}*/


		// 공익제보센터 Tab Design check
		var tabText = $(".sec_tab_blk .tnb li >a ").text();
		var findStringComp = "부패행위 제보";
		if(tabText.indexOf(findStringComp) != -1) {
			$(".sec_tab_blk").addClass("blk_flex_tab");
			$(".sec_tab_blk .tnb").addClass("tab_ty_report");
		}
		// 통합자료실-과자료실 Tab Design check
		var findStringDepart = "과자료실";
		if(tabText.indexOf(findStringDepart) != -1) {
			$(".sec_tab_blk").addClass("blk_flex_tab");
			$(".sec_tab_blk").next().addClass("depart_box_h");
		}

		if($(".sec_tab_blk").hasClass("blk_flex_tab") == 1) {
			//alert('a');
			$(".sec_tab_blk").parent().css("display","flex");
		}


		// 조직도 부서 cont 매칭 check
		var findStringOrgan = $("#organ_depart_name").html();
		$(".sec_organ_mn a").removeClass("on").parent().removeClass("on");
		$(".sec_organ_mn a:contains("+findStringOrgan+"):first").addClass("on").parent(".dep2lst2, strong, dt").addClass("on");



		// datepicket
		$("#sch_date_s, #sch_date_e").datepicker({
			dateFormat: 'yy-mm-dd' //Input Display Format 변경
			,showOtherMonths: true //빈 공간에 현재월의 앞뒤월의 날짜를 표시
			,showMonthAfterYear:true //년도 먼저 나오고, 뒤에 월 표시
			//,changeYear: true //콤보박스에서 년 선택 가능
			//,changeMonth: true //콤보박스에서 월 선택 가능
			,showOn: "button" //button:버튼을 표시하고,버튼을 눌러야만 달력 표시 ^ both:버튼을 표시하고,버튼을 누르거나 input을 클릭하면 달력 표시
			,buttonImage: "../resource/images/btn_cal.gif" //버튼 이미지 경로
			,buttonImageOnly: true //기본 버튼의 회색 부분을 없애고, 이미지만 보이게 함
			,buttonText: "선택" //버튼에 마우스 갖다 댔을 때 표시되는 텍스트
			,yearSuffix: "년" //달력의 년도 부분 뒤에 붙는 텍스트
			,monthNamesShort: ['1','2','3','4','5','6','7','8','9','10','11','12'] //달력의 월 부분 텍스트
			,monthNames: ['1월','2월','3월','4월','5월','6월','7월','8월','9월','10월','11월','12월'] //달력의 월 부분 Tooltip 텍스트
			,dayNamesMin: ['일','월','화','수','목','금','토'] //달력의 요일 부분 텍스트
			,dayNames: ['일요일','월요일','화요일','수요일','목요일','금요일','토요일'] //달력의 요일 부분 Tooltip 텍스트
			//,minDate: "-1M" //최소 선택일자(-1D:하루전, -1M:한달전, -1Y:일년전)
			//,maxDate: "+1M" //최대 선택일자(+1D:하루후, -1M:한달후, -1Y:일년후)
		});

		//초기값을 오늘 날짜로 설정
		$('#sch_date_s, #sch_date_e').datepicker('setDate', 'today');

		//공익제보센터 자세히보기
		$('.faqOnBtn').click(function(){
			var viewName = $(this).attr("id");
			$(".faq_blk").removeClass("on");
			$(".faq_blk." + viewName).addClass("on");
		});
	}






//---------------------------------------------------------------------------------------------------
//  mobile(1000px 이하) - web(1200px 초과) Responsive 설정
//---------------------------------------------------------------------------------------------------
	function adjustResp(width) {
		width = parseInt(width);
		if (width < 800) { // #############################################>>  모바일 적용

			tab_select();
			notice_tab();
			notice_popup_mobile();
			gnb_mobile();
			gnb_mobile_main();
			agency_link();
			sns_share_mobile();
			search_mobile();
			tab_toggle_cont();
			qna_cont();
			mobile_setting();

		} else { // ###############################################>>  web 적용

			notice_tab();
			notice_popup();
			tab_select();
			agency_link();
			gnb_web();
			lnbMenu();
			sns_share();
			tab_toggle_cont();
			qna_cont();
			web_setting();

		}


	}

//---------------------------------------------------------------------------------------------------
//  실행!!!!
//---------------------------------------------------------------------------------------------------
	$(function() {
		adjustResp($(this).width());
		$(window).resize(function() {
			adjustResp($(this).width());
		});
	});


});




