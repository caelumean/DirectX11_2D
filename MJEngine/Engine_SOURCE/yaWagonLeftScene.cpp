#include "yaWagonLeftScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCamera.h"`

namespace ya
{
	WagonLeftScene::WagonLeftScene()
	{
	}
	WagonLeftScene::~WagonLeftScene()
	{
	}
	void WagonLeftScene::Initialize()
	{
		GameObject* WagonLeftBG = new GameObject;
		AddGameObject(eLayerType::BG1, WagonLeftBG);

		MeshRenderer* mr = WagonLeftBG->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"WagonLeft"));

		WagonLeftBG->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0f));
	}
	void WagonLeftScene::Update()
	{
		Scene::Update();
		if (Input::GetKey(eKeyCode::SPACE))
		{
			SceneManager::LoadScene(L"WagonMiddleScene");
			Scene* next = SceneManager::GetActiveScene();
			next->Initialize();
		}
	}
	void WagonLeftScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void WagonLeftScene::Render()
	{
		Scene::Render();
	}
}