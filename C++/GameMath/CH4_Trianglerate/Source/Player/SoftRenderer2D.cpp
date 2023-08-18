
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
Vector2 currentPosotion;
float currentScale = 10.0f;
float currentDegree = 0.f;

// 게임 로직을 담당하는 함수
void SoftRenderer::Update2D(float InDeltaSeconds)
{
	// 게임 로직에서 사용하는 모듈 내 주요 레퍼런스
	auto& g = Get2DGameEngine();
	const InputManager& input = g.GetInputManager();

	// 게임 로직의 로컬 변수
	static float moveSpeed = 100.f;
	static float scaleMin = 5.f;
	static float scaleMax = 20.f;
	static float scaleSpeed = 20.f;
	static float duration = 1.5f;
	static float elapsedTime2 = 0.f;
	static float rotateSpeed = 180.f;

	Vector2 inputVector = Vector2(input.GetAxis(InputAxis::XAxis), input.GetAxis(InputAxis::YAxis)).GetNormalize();
	Vector2 deltaPosition = inputVector * moveSpeed * InDeltaSeconds;
	float deltaScale = input.GetAxis(InputAxis::ZAxis) * scaleSpeed * InDeltaSeconds;
	float deltaDegree = input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds;

	elapsedTime2 += InDeltaSeconds;
	elapsedTime2 = Math::FMod(elapsedTime2, duration);
	float currentRad = (elapsedTime2 / duration) * Math::TwoPI;
	float alpha = (sinf(currentRad) + 1) * 0.5f;

	currentPosotion += deltaPosition;
	//currentScale = Math::Clamp(currentScale + deltaScale, scaleMin, scaleMax);
	currentScale = Math::Lerp(scaleMin, scaleMax, alpha);
	currentDegree += deltaDegree;
}

// 렌더링 로직을 담당하는 함수
void SoftRenderer::Render2D()
{
	// 렌더링 로직에서 사용하는 모듈 내 주요 레퍼런스
	auto& r = GetRenderer();
	const auto& g = Get2DGameEngine();

	// 배경에 격자 그리기
	DrawGizmo2D();

	// 렌더링 로직의 로컬 변수
	float rad = 0.f;
	static float increment = 0.001f;
	static std::vector<Vector2> hearts;
	HSVColor hsv(0.f, 1.f, 0.85f);

	// 시공의 폭풍 구현
	static float halfSize = 100.f;
	static std::vector<Vector2> squares;

	if (squares.empty())
	{
		for (float x = -halfSize; x <= halfSize; x += 0.25f)
		{
			for (float y = -halfSize; y <= halfSize; y += 0.25f)
			{
				squares.push_back(Vector2(x, y));
			}
		}
	}

	// 하트를 구성하는 점 생성
	if (hearts.empty())
	{
		for (rad = 0.f; rad < Math::TwoPI; rad += increment)
		{
			// 하트 방정식
			// x와 y를 구하기.
			// hearts.push_back(Vector2(x, y));
			float sin = sinf(rad);
			float cos = cosf(rad);
			float cos2 = cosf(2 * rad);
			float cos3 = cosf(3 * rad);
			float cos4 = cosf(4 * rad);
			float x = 16.f * sin * sin * sin;
			float y = 13 * cos - 5 * cos2 - 2 * cos3 - cos4;
			hearts.push_back(Vector2(x, y));
		}
	}
	// 0.5초 주기로 깜빡이기
	static float elapsedTime = 0.0f;
	static bool isVisible = true;

	elapsedTime += 1.0f / 60.0f; // 업데이트 빈도에 따라 조정 필요

	if (elapsedTime >= 0.1f)
	{
		isVisible = !isVisible;
		elapsedTime = 0.0f;
	}
	//각도에 해당하는 사인과 코사인값 얻기 
	float sin = 0.f, cos = 0.f;
	Math::GetSinCos(sin, cos, currentDegree);

	rad = 0.f;
	for (auto const& v : hearts)
	{
		rad += increment;
		// 1. 점에 크기를 적용
		Vector2 scaledV = v * currentScale;

		// 2. 크기가 변한 점을 회전
		Vector2 rotateV = Vector2(scaledV.X * cos - scaledV.Y * sin, scaledV.X * sin + scaledV.Y * cos);
		
		// 3. 회전시킨 점을 이동
		Vector2 translatedV = rotateV + currentPosotion;

		hsv.H = rad / Math::TwoPI;

		// 윤곽선 그리기 
		//r.DrawPoint(v * currentScale + currentPosotion, hsv.ToLinearColor());
		r.DrawPoint(translatedV, hsv.ToLinearColor());

		if (isVisible)  // 색칠할 부분만 isVisible 상태에 따라 그리기
		{
			Vector2 origin = Vector2(0, 0);
			Vector2 direction = (v - origin).GetNormalize();
			for (float t = 0; t <= 1; t += 0.01f)
			{
				Vector2 pointOnLine = origin + direction * t * v.Size();

				// 1. 점에 크기를 적용
				Vector2 scaledPoint = pointOnLine * currentScale;

				// 2. 크기가 변한 점을 회전
				Vector2 rotatedPoint = Vector2(scaledPoint.X * cos - scaledPoint.Y * sin, scaledPoint.X * sin + scaledPoint.Y * cos);

				// 3. 회전시킨 점을 이동
				Vector2 translatedPoint = rotatedPoint + currentPosotion;

				r.DrawPoint(translatedPoint, hsv.ToLinearColor());
			}
		}


		/*
		r.PushStatisticText(std::string("Position : ") + currentPosotion.ToString());
		r.PushStatisticText(std::string("scale : ") + std::to_string(currentScale));
		r.PushStatisticText(std::string("Degree : ") + std::to_string(currentDegree));
		*/
	}

	// 시공의 폭풍 구현하기
	// 현재 화면의 크기로부터 길이를 비교할 기준양 정하기
	static float maxLength = Vector2(_ScreenSize.X, _ScreenSize.Y).Size() * 0.5f;

	// 원을 구성하는 점을 그린다.
	for (auto const& v : squares)
	{
		// r극 좌표계 변경
		Vector2 polarV = v.ToPolarCoordinate();

		// 극좌표계의 각 정보로부터 색상을 결정한다.
		if (polarV.Y < 0.f)
		{
			polarV.Y += Math::TwoPI;
		}
		hsv.H = polarV.Y / Math::TwoPI;

		// 극좌표계의 크기 정보로부터 회전량 결정
		float ratio = polarV.X / maxLength;
		float weight = Math::Lerp(1.f, 5.f, ratio);

		polarV.Y += Math::Deg2Rad(currentDegree) * weight;

		// 최종 값을 데카르트 좌표계로 변환하기
		Vector2 cartesianV = polarV.ToCartesianCoordinate();
		r.DrawPoint(cartesianV, hsv.ToLinearColor());
	}
}

// 메시를 그리는 함수
void SoftRenderer::DrawMesh2D(const class DD::Mesh& InMesh, const Matrix3x3& InMatrix, const LinearColor& InColor)
{
}

// 삼각형을 그리는 함수
void SoftRenderer::DrawTriangle2D(std::vector<DD::Vertex2D>& InVertices, const LinearColor& InColor, FillMode InFillMode)
{
}
