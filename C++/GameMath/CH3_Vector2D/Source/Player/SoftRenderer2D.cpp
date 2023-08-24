
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

Vector2 currentPosition(100.f, 100.f);
Vector2 currentPosition2(100.f, 100.f);


// 게임 로직을 담당하는 함수
void SoftRenderer::Update2D(float InDeltaSeconds)
{
	// 게임 로직에서 사용하는 모듈 내 주요 레퍼런스
	auto& g = Get2DGameEngine();
	const InputManager& input = g.GetInputManager();
	
	// 게임 로직의 로컬 변수
	static float moveSpeed = 100.f;

	Vector2 inputVector = Vector2(input.GetAxis(InputAxis::XAxis), input.GetAxis(InputAxis::YAxis));
	Vector2 deltaPosition = inputVector * moveSpeed * InDeltaSeconds;
	
	Vector2 inputVector2 = Vector2(input.GetAxis(InputAxis::XAxis), input.GetAxis(InputAxis::YAxis)).GetNormalize();
	Vector2 deltaPosition2 = inputVector2 * moveSpeed * InDeltaSeconds;

	// 물체의 최종 상태 설정
	currentPosition += deltaPosition;

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
	
	// line그리기
	static float lineLength = 500.f;
	Vector2 lineStart = currentPosition * lineLength;
	Vector2 lineEnd = currentPosition * -lineLength;
	r.DrawLine(lineStart, lineEnd, LinearColor::Black);

	r.DrawPoint(currentPosition, LinearColor::Red);
	r.DrawPoint(currentPosition + Vector2::UnitX, LinearColor::Red);
	r.DrawPoint(currentPosition - Vector2::UnitX, LinearColor::Red);
	r.DrawPoint(currentPosition + Vector2::UnitY, LinearColor::Red);
	r.DrawPoint(currentPosition - Vector2::UnitY, LinearColor::Red);
	r.DrawPoint(currentPosition + Vector2::One, LinearColor::Red);
	r.DrawPoint(currentPosition - Vector2::One, LinearColor::Red);
	r.DrawPoint(currentPosition + Vector2(1.f, -1.f), LinearColor::Red);
	r.DrawPoint(currentPosition - Vector2(1.f, -1.f), LinearColor::Red);

	r.PushStatisticText("Coordinate : " + currentPosition.ToString());

	//// y = x^2 그래프 그리기
	//static float step = 1.0f;  // x값의 간격입니다. 이 값은 원하는 대로 조절할 수 있습니다.
	//LinearColor graphColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black

	//float scale = 1.0f / _Grid2DUnit; // 이 값은 y = x^2 그래프의 y 값을 격자 크기에 맞게 스케일링합니다.

	//Vector2 prevPoint = currentPosition + Vector2(-lineLength, (-lineLength) * (-lineLength) * scale);
	//for (float x = -lineLength + step; x <= lineLength; x += step)
	//{
	//	float y = x * x;
	//	Vector2 currentPoint = currentPosition + Vector2(x, y * scale);
	//	r.DrawLine(prevPoint, currentPoint, graphColor);
	//	prevPoint = currentPoint;
	//}

	// 렌더링 로직의 로컬 변수
	// Circle그리기
	static float radius = 50.f;
	static std::vector<Vector2> circles;

	if (circles.empty())
	{
		for (float x = -radius; x <= radius; ++x)
		{
			for (float y = -radius; y <= radius; ++y)
				{
				Vector2 pointToTest = Vector2(x, y);
				float squaredLength = pointToTest.SizeSquared();
				if (squaredLength <= radius * radius)
				{
					circles.push_back(Vector2(x, y));
				}
			}
		}
	}

	// 원을 구성하는 벡터를 붉은색으로 표시하기
	for (auto const& v : circles)
	{
		r.DrawPoint(v + currentPosition, LinearColor::Red);
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
