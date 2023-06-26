#include "yaWagonMiddleScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCamera.h"`

namespace ya
{
	WagonMiddleScene::WagonMiddleScene()
	{
	}
	WagonMiddleScene::~WagonMiddleScene()
	{
	}
	void WagonMiddleScene::Initialize()
	{
		GameObject* WagonMiddleBG = new GameObject;
		AddGameObject(eLayerType::BG1, WagonMiddleBG);

		MeshRenderer* mr = WagonMiddleBG->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"WagonMiddle"));

		WagonMiddleBG->GetComponent<Transform>()->SetScale(Vector3(2.2f, 2.0f, 1.0f));
	}
	void WagonMiddleScene::Update()
	{
		if (Input::GetKey(eKeyCode::LEFT))
		{
			SceneManager::LoadScene(L"WagonLeftScene");
			Scene* next = SceneManager::GetActiveScene();
			next->Initialize();
		}
		else if (Input::GetKey(eKeyCode::RIGHT))
		{
			SceneManager::LoadScene(L"WagonRightScene");
			Scene* next = SceneManager::GetActiveScene();
			next->Initialize();
		}
		else if (Input::GetKey(eKeyCode::DOWN))
		{
			SceneManager::LoadScene(L"WagonBottomScene");
			Scene* next = SceneManager::GetActiveScene();
			next->Initialize();
		}
		Scene::Update();
	}
	void WagonMiddleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void WagonMiddleScene::Render()
	{
		Scene::Render();
	}
}