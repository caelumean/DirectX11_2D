#include "yaWagonBottomScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCamera.h"`

namespace ya 
{
	WagonBottomScene::WagonBottomScene()
	{
	}
	WagonBottomScene::~WagonBottomScene()
	{
	}
	void WagonBottomScene::Initialize()
	{
		GameObject* WagonBottomBG = new GameObject;
		AddGameObject(eLayerType::BG1, WagonBottomBG);

		MeshRenderer* mr = WagonBottomBG->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"WagonBottom"));

		WagonBottomBG->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0f));
	}
	void WagonBottomScene::Update()
	{
		Scene::Update();
		if (Input::GetKey(eKeyCode::SPACE))
		{
			SceneManager::LoadScene(L"WagonMiddleScene");
			Scene* next = SceneManager::GetActiveScene();
			next->Initialize();
		}
	}
	void WagonBottomScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void WagonBottomScene::Render()
	{
		Scene::Render();
	}
}