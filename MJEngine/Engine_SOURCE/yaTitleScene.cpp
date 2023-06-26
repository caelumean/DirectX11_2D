#include "yaTitleScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCamera.h"`

namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		GameObject* TitleBG = new GameObject;
		AddGameObject(eLayerType::BG1, TitleBG);
	

		MeshRenderer* mr = TitleBG->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"TitleBG"));

		TitleBG->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0f));


		GameObject* TitleText = new GameObject;;
		AddGameObject(eLayerType::BG2, TitleText);

		MeshRenderer* mt = TitleText->AddComponent<MeshRenderer>();
		mt->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mt->SetMaterial(Resources::Find<Material>(L"TitleText"));

		TitleText->GetComponent<Transform>()->SetScale(Vector3(0.5f, 0.5f, 1.0f));
		TitleText->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));

	}
	void TitleScene::Update()
	{
		Scene::Update();
		if (Input::GetKey(eKeyCode::SPACE))
		{
			SceneManager::LoadScene(L"WagonMiddleScene");
			Scene* next = SceneManager::GetActiveScene();
			next->Initialize();
		}
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TitleScene::Render()
	{
		Scene::Render();
	}
}
