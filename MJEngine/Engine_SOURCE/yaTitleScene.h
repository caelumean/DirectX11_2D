#pragma once
#include "yaScene.h"
namespace ya
{
    class TitleScene : public Scene
    {
    public:
        TitleScene();
        virtual ~TitleScene();

    public:
        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;
    };
}
