#pragma once
#include "../Core/SceneManager.h"
#include "../Core/components.h"

class StartScene : public SceneManager {


    void Init() override; 

private:
    Object* start_button;
    Image* startBttn_image; 
};
