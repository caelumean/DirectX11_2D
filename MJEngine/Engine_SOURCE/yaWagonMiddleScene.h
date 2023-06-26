#pragma once
#include "yaScene.h"
namespace ya
{
	class WagonMiddleScene : public Scene
	{
	public:
		WagonMiddleScene();
		virtual ~WagonMiddleScene();

	public :
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};
}


