#pragma once
#include "Engine/GameObject.h"
#include <vector>

using std::vector;

class Stage :
    public GameObject
{
    int hFloor_;
    int hWall_;
    vector<vector<int>> stageData_;
public:
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Stage(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
