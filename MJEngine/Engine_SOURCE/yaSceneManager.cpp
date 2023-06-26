#include "yaSceneManager.h"

// Scene
#include "yaTitleScene.h"
#include "yaWagonMiddleScene.h"
#include "yaWagonLeftScene.h"
#include "yaWagonRightScene.h"
#include "yaWagonBottomScene.h"

namespace ya
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes;

	void SceneManager::Initialize()
	{
		//PlayScene* test = new PlayScene();

		/*mActiveScene = new PlayScene();
		mScenes.insert(std::make_pair(L"PlayScene", mActiveScene));*/

		mActiveScene = new TitleScene();
		mScenes.insert(std::make_pair(L"TitleScene", mActiveScene));

		mActiveScene = new WagonMiddleScene();
		mScenes.insert(std::make_pair(L"WagonMiddleScene", mActiveScene));

		mActiveScene = new WagonLeftScene();
		mScenes.insert(std::make_pair(L"WagonLeftScene", mActiveScene));

		mActiveScene = new WagonRightScene();
		mScenes.insert(std::make_pair(L"WagonRightScene", mActiveScene));

		mActiveScene = new WagonBottomScene();
		mScenes.insert(std::make_pair(L"WagonBottomScene", mActiveScene));

		mActiveScene = mScenes[L"TitleScene"]; 

		mActiveScene->Initialize();
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render()
	{
		mActiveScene->Render();
	}

	void SceneManager::Release()
	{
		for (auto iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	Scene* SceneManager::LoadScene(std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene->OnExit();
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}
}
