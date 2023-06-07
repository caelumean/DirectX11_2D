#include "yaApplication.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaRenderer.h"


namespace ya
{
	Vector4 pos = Vector4(0.f, 0.f, 0.f, 1.f);

	Application::Application()
		: graphicDevice(nullptr)
		, mHwnd(NULL)
		, mWidth(-1)
		, mHeight(-1)
	{

	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Initialize()
	{
		Time::Initiailize();
		Input::Initialize();

		renderer::Initialize();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();

		float x = 0.0f;
		float y = 0.0f;

		if (Input::GetKey(eKeyCode::RIGHT))
			x += 1.0f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::LEFT))
			x -= 1.0f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::UP))
			y += 1.0f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::DOWN))
			y -= 1.0f * Time::DeltaTime();
		pos.x += x;
		pos.y += y;

		ya::graphics::GetDevice()->SetConstantBuffer(ya::renderer::triangleConstantBuffer, &pos, sizeof(Vector4));
		ya::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, ya::renderer::triangleConstantBuffer);
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		Time::Render();

		graphicDevice->Draw();
	}

	void Application::SetWindow(HWND hwnd, UINT width, UINT height)
	{
		if (graphicDevice == nullptr)
		{
			mHwnd = hwnd;
			mWidth = width;
			mHeight = height;

			graphicDevice = std::make_unique<ya::graphics::GraphicDevice_Dx11>();
			ya::graphics::GetDevice() = graphicDevice.get();
		}

		RECT rt = { 0, 0, (LONG)width , (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}

}
