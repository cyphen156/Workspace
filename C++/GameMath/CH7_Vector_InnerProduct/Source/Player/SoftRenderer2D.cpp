
#include "Precompiled.h"
#include "SoftRenderer.h"
#include <random>
using namespace CK::DD;

// 격자를 그리는 함수
void SoftRenderer::DrawGizmo2D()
{
	auto& r = GetRenderer();
	const auto& g = Get2DGameEngine();

	// 그리드 색상
	LinearColor gridColor(LinearColor(0.8f, 0.8f, 0.8f, 0.3f));

	// 뷰의 영역 계산
	Vector2 viewPos = g.GetMainCamera().GetTransform().GetPosition();
	Vector2 extent = Vector2(_ScreenSize.X * 0.5f, _ScreenSize.Y * 0.5f);

	// 좌측 하단에서부터 격자 그리기
	int xGridCount = _ScreenSize.X / _Grid2DUnit;
	int yGridCount = _ScreenSize.Y / _Grid2DUnit;

	// 그리드가 시작되는 좌하단 좌표 값 계산
	Vector2 minPos = viewPos - extent;
	Vector2 minGridPos = Vector2(ceilf(minPos.X / (float)_Grid2DUnit), ceilf(minPos.Y / (float)_Grid2DUnit)) * (float)_Grid2DUnit;
	ScreenPoint gridBottomLeft = ScreenPoint::ToScreenCoordinate(_ScreenSize, minGridPos - viewPos);

	for (int ix = 0; ix < xGridCount; ++ix)
	{
		r.DrawFullVerticalLine(gridBottomLeft.X + ix * _Grid2DUnit, gridColor);
	}

	for (int iy = 0; iy < yGridCount; ++iy)
	{
		r.DrawFullHorizontalLine(gridBottomLeft.Y - iy * _Grid2DUnit, gridColor);
	}

	ScreenPoint worldOrigin = ScreenPoint::ToScreenCoordinate(_ScreenSize, -viewPos);
	r.DrawFullHorizontalLine(worldOrigin.Y, LinearColor::Red);
	r.DrawFullVerticalLine(worldOrigin.X, LinearColor::Green);
}

// 게임 오브젝트 목록


// 최초 씬 로딩을 담당하는 함수
void SoftRenderer::LoadScene2D()
{
	// 최초 씬 로딩에서 사용하는 모듈 내 주요 레퍼런스
	auto& g = Get2DGameEngine();

}

// 게임 로직과 렌더링 로직이 공유하는 변수

/// 7_1 예제
/// 시야각 계산하기
float fovAngle = 60.f;	// 시야각	
Vector2 playerPosition(0.f, 0.f);	// 위치값
LinearColor playerColor = LinearColor::Gray;
Vector2 targetPosition(0.f, 100.f);	// 목표 위치값
bool isVisible = false;
LinearColor nonVisibleColor = LinearColor::Blue;
LinearColor targetColor = nonVisibleColor;
LinearColor visibleColor = LinearColor::Red;

/// 7_2 예제
/// 조명 모델 구현하기
Vector2 lightPosition;	// 광원
LinearColor lightColor;
Vector2 circlePosition;	// 빛을 반사할 물체


/// 7_3 예제
/// 직교투영
Vector2 point(0.f, 250.f);
Vector2 lineStart(-400.f, 0.f);
Vector2 lineEnd(400.f, 0.f);

// 게임 로직을 담당하는 함수
void SoftRenderer::Update2D(float InDeltaSeconds)
{
	// 게임 로직에서 사용하는 모듈 내 주요 레퍼런스
	auto& g = Get2DGameEngine();
	const InputManager& input = g.GetInputManager();

	// 게임 로직의 로컬 변수
	static float moveSpeed = 100.f;	

	/// 7_1 예제
	/// 시야각 계산하기
	//	랜덤 위치 변환 범위
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static float duration = 3.f;
	static float elapsedTime = 0.f;
	static std::uniform_real_distribution<float> randomPosX(-300.f, 300.f);
	static std::uniform_real_distribution<float> randomPosY(-200.f, 200.f);
	
	static Vector2 targetStart = targetPosition;
	static Vector2 targetDestination = Vector2(randomPosX(mt), randomPosY(mt));

	static float halfFovCos = cosf(Math::Deg2Rad(fovAngle * 0.5f));
	elapsedTime = Math::Clamp(elapsedTime + InDeltaSeconds, 0.f, duration);

	// 지정한 시간이 경과하면 새로운 이동 지점을 랜덤하게 설정
	if (elapsedTime == duration)
	{
		targetStart = targetDestination;
		targetPosition = targetDestination;
		targetDestination = Vector2(randomPosX(mt), randomPosY(mt));

		elapsedTime = 0.f;
	}
	else // 비율에 따라 목표지점까지 선형보간하면서 이동
	{
		float ratio = elapsedTime / duration;
		targetPosition = Vector2(
			Math::Lerp(targetStart.X, targetDestination.X, ratio),
			Math::Lerp(targetStart.Y, targetDestination.Y, ratio)
		);
	}

	Vector2 inputVector = Vector2(input.GetAxis(InputAxis::XAxis), input.GetAxis(InputAxis::YAxis)).GetNormalize();
	Vector2 deltaPosition = inputVector * moveSpeed * InDeltaSeconds;

	// 물체의 최종 상태 설정

	Vector2 f = Vector2::UnitY;
	Vector2 v = (targetPosition - playerPosition).GetNormalize();
	if ((v.Dot(f) >= halfFovCos && v.Dot(f) >= -halfFovCos))
	{
		targetColor = visibleColor;
	}
	else
	{
		targetColor = nonVisibleColor;
	}
	playerPosition += deltaPosition;


	/// 7_2 예제
	/// 조명 모델 구현하기
	static float duration_2 = 20.0f;
	static float elapsedTime_2 = 0.0f;
	static float currentDegree_2 = 0.0f;
	static float lightDistance = 200.0f;
	static HSVColor lightHSVColor;

	// 경과된 시간에 따른 현재 각과 이를 사용한 [0, 1] 값의 생성
	elapsedTime_2 += InDeltaSeconds;
	elapsedTime_2 = Math::FMod(elapsedTime_2, duration_2);
	float currentRad = (elapsedTime_2 / duration_2) * Math::TwoPI;	// 현재 각 라디안으로 계산하기
	float alpha = (sinf(currentRad) + 1) * 0.5f;

	// [0, 1]을 사용해 주기적으로 크기 반복하기
	currentDegree_2 = Math::Lerp(0.f, 360.f, alpha);

	// 광원 좌표, 색상
	float sin = 0.0f, cos = 0.0f;
	Math::GetSinCosRad(sin, cos, currentRad);
	lightPosition = Vector2(sin, cos) * lightDistance;
	lightHSVColor.H = currentRad * Math::InvPI * 0.5f;
	lightColor = lightHSVColor.ToLinearColor();


	/// 7_3 예제
	/// 직교투영
	static float duration_3 = 6.f;
	static float elapsedTime_3 = 0.0f;
	static float currentDegree_3 = 0.0f;
	static float rotateSpeed_3 = 180.f;
	static float distance_3 = 250.0f;
	static std::uniform_real_distribution<float> randomY(-200.f, 200.f);

	if (elapsedTime_3 == duration_3)
	{
		lineStart = Vector2(-400.f, randomY(mt));
		lineEnd = Vector2(-400.f, randomY(mt));
		elapsedTime_3 = 0;
	}

	// 점의 위치를 결정
	currentDegree_3 = Math::FMod(currentDegree_3 + rotateSpeed_3 * InDeltaSeconds, 360.f);
	float sin_3 = 0.f, cos_3 = 0.f;
	Math::GetSinCos(sin, cos, currentDegree_3);
	point = Vector2(cos, sin) * distance_3;
}

// 렌더링 로직을 담당하는 함수
void SoftRenderer::Render2D()
{
	// 렌더링 로직에서 사용하는 모듈 내 주요 레퍼런스
	auto& r = GetRenderer();
	const auto& g = Get2DGameEngine();

	// 렌더링 로직의 로컬 변수

	/// 7_1 예제
	/// 시야각 계산하기
	static float radius = 5.f;
	static std::vector<Vector2> sphere;
	static float sightLength = 300.f;

	if (sphere.empty())
	{
		for (float x = -radius; x <= radius; ++x)
		{
			for (float y = -radius; y <= radius; ++y)
			{
				Vector2 target(x, y);
				float sizeSquared = target.SizeSquared();
				float rr = radius * radius;
				if (sizeSquared < rr)
				{
					sphere.push_back(target);
				}
			}
		}
	}

	// 플레이어 렌더링. 
	// 플레이어 렌더링. 
	float halfFovSin = 0.f, halfFovCos = 0.f;
	Math::GetSinCos(halfFovSin, halfFovCos, fovAngle * 0.5f);

	r.DrawLine(playerPosition, playerPosition + Vector2(sightLength * halfFovSin, sightLength * halfFovCos), playerColor);
	r.DrawLine(playerPosition, playerPosition + Vector2(-sightLength * halfFovSin, sightLength * halfFovCos), playerColor);
	r.DrawLine(playerPosition, playerPosition + Vector2::UnitY * sightLength * 0.2f, playerColor);
	for (auto const& v : sphere)
	{
		r.DrawPoint(v + playerPosition, playerColor);
	}
	
	// 타겟 렌더링
	for (auto const& v : sphere)
	{
		r.DrawPoint(v + targetPosition, targetColor);
	}

	// 주요 정보 출력
	r.PushStatisticText(std::string("Player Position : ") + playerPosition.ToString());
	r.PushStatisticText(std::string("Target Position : ") + targetPosition.ToString());

	/// 7_2 예제
	/// 조명 모델 구현하기
	
	// 광원과 원 그리기
	static std::vector<Vector2> light;
	static float lightRadius = 10.0f;
	static std::vector<Vector2> circle;
	static float circleRadius = 50.0f;

	// 광원을 표현하는 구체
	if (light.empty())
	{
		float lightRadius = 10.f;
		for (float x = -lightRadius; x <= lightRadius; ++x)
		{
			for (float y = -lightRadius; y <= lightRadius; ++y)
			{
				Vector2 target(x, y);
				float sizeSquared = target.SizeSquared();
				float rr = lightRadius * lightRadius;
				if (sizeSquared < rr)
				{
					light.push_back(target);
				}
			}
		}
	}

	// 빛을 받는 물체
	if (circle.empty())
	{
		for (float x = -circleRadius; x <= circleRadius; ++x)
		{
			for (float y = -circleRadius; y <= circleRadius; ++y)
			{
				Vector2 target(x, y);
				float sizeSquared = target.SizeSquared();
				float rr = circleRadius * circleRadius;
				if (sizeSquared < rr)
				{
					circle.push_back(target);
				}
			}
		}
	}
	circlePosition = playerPosition;

	// 광원 그리기
	static float lightLineLength = 50.f;
	r.DrawLine(lightPosition, circlePosition - lightPosition.GetNormalize() * lightLineLength, lightColor);
	for (auto const& v : light)
	{
		r.DrawPoint(v + lightPosition, lightColor);
	}

	// 광원을 받는 구체의 모든 픽셀에 NdotL을 계산해 음영을 산출하고 이를 최종 색상에 반영
	for (auto const& v : circle)
	{
		Vector2 n = (v + circlePosition - circlePosition).GetNormalize(); // 원의 중심 기준으로 노멀 벡터 계산
		Vector2 l = (lightPosition - (v + circlePosition)).GetNormalize(); // 광원 방향 벡터
		float shading = Math::Clamp(n.Dot(l), 0.f, 1.f); // 조명 효과 계산
		r.DrawPoint(v + circlePosition, lightColor * shading); // 원의 중심(circlePosition) 기준으로 색상 적용
	}

	// 현재 조명의 위치를 화면에 출력
	r.PushStatisticText(std::string("Position : ") + lightPosition.ToString());

	/// 7_3 예제
	/// 직교투영
	// 붉은 색으로 점 그리기
	for (auto const& v : circle)
	{
		r.DrawPoint(v + point, LinearColor::Red);
	}

	// 투영할 라인 그리기
	r.DrawLine(lineStart, lineEnd, LinearColor::Black);
	r.DrawLine(lineStart, point, LinearColor::Red);

	// 투영된 위치와 거리 계산
	Vector2 unitV = (lineEnd - lineStart).GetNormalize();
	Vector2 u = point - lineStart;
	Vector2 projV = unitV * (u.Dot(unitV));
	Vector2 projectedPoint = lineStart + projV;
	float distance = (projectedPoint - point).Size();

	// 투영된 점 그리기
	for (auto const& v : circle)
	{
		r.DrawPoint(v + projectedPoint, LinearColor::Blue);
	}

	// 투영 라인 그리기
	r.DrawLine(projectedPoint, point, LinearColor::Gray);

	// 관련 데이터 화면 출력
	r.PushStatisticText(std::string("Point : ") + point.ToString());
	r.PushStatisticText(std::string("Projected Point : ") + projectedPoint.ToString());
	r.PushStatisticText(std::string("Distance : ") + std::to_string(distance));
}

// 메시를 그리는 함수
void SoftRenderer::DrawMesh2D(const class DD::Mesh& InMesh, const Matrix3x3& InMatrix, const LinearColor& InColor)
{
}

// 삼각형을 그리는 함수
void SoftRenderer::DrawTriangle2D(std::vector<DD::Vertex2D>& InVertices, const LinearColor& InColor, FillMode InFillMode)
{
}
