#include "FirstScene.h"        
#include "Game.h"


FirstScene::FirstScene()
{
    buildScene();
}

void FirstScene::buildScene()
{
    buildShaders();
    buildObjects();
    buildLights();
}

/* must be called before buildObjects and buildLights */
void FirstScene::buildShaders()
{
    shader = new Shader(RESOURCES_PATH "shaders/texturedObjWithLight.vs", RESOURCES_PATH "shaders/texturedObjWithLight.fs");
    skyboxShader = new Shader(RESOURCES_PATH "shaders/skybox.vs", RESOURCES_PATH "shaders/skybox.fs");
}

void FirstScene::buildObjects()
{

    shader->use();
    stbi_set_flip_vertically_on_load(true);
    // first cube object
    cube1 = new prim3d::Cube();
    // set initial world space
    cube1->setScale(glm::vec3(2.0f));
    cube1->setRotation(45.0f, glm::vec3(1.0f));
    cube1->setTranslation(glm::vec3(0.0f, 0.0f, -4.0f));
    cube1->updateModelMatrix();
    cube1->setTexture("texture_diffuse", RESOURCES_PATH "textures/container2.png");
    cube1->setTexture("texture_specular", RESOURCES_PATH "textures/container2_specular.png");

    // backpack model loading using assimp
    backpack = new sm3d::Model(RESOURCES_PATH "objects/backpack/backpack.obj");
    backpack->setScale(glm::vec3(0.5f));
    backpack->setTranslation(glm::vec3(3.0f, 2.0f, -5.0f));
    backpack->updateModelMatrix();

    // skybox configuration
    stbi_set_flip_vertically_on_load(false);
    skybox = new prim3d::Skybox();
    std::vector<std::string> skyboxFaces = {
        RESOURCES_PATH "textures/SB_land/right.png",
        RESOURCES_PATH "textures/SB_land/left.png",
        RESOURCES_PATH "textures/SB_land/up.png",
        RESOURCES_PATH "textures/SB_land/down.png",
        RESOURCES_PATH "textures/SB_land/front.png",
        RESOURCES_PATH "textures/SB_land/back.png"
    };
    skybox->setTextures(skyboxFaces);

}

void FirstScene::buildLights()
{
    shader->setInt("material.texture_diffuse1", 0);
    shader->setInt("material.texture_specular", 1);

    // directional light
    shader->setVec3("dirLight.direction", -0.6f, -1.0f, -0.3f);
    shader->setVec3("dirLight.ambient", 0.03f, 0.03f, 0.03f);
    shader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
    shader->setVec3("dirLight.specular", 0.6f, 0.6f, 0.6f);
    
    // spotLight
    shader->setVec3("spotLight.position", camera.Position);
    shader->setVec3("spotLight.direction", camera.Front);
    shader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
    shader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
    shader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
    shader->setFloat("spotLight.constant", 1.0f);
    shader->setFloat("spotLight.linear", 0.09f);
    shader->setFloat("spotLight.quadratic", 0.032f);
    shader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    shader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
}

void FirstScene::renderLevel()
{
    glEnable(GL_DEPTH_TEST);

    shader->use();
    shader->setVec3("viewPos", camera.Position);

    // update lights
    // spotLight
    shader->setVec3("spotLight.position", camera.Position);
    shader->setVec3("spotLight.direction", camera.Front);

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    shader->setMat4("projection", projection);
    shader->setMat4("view", view);

    // world transformation
    // cube1
    cube1->setRotation((float)glfwGetTime() * 40.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    cube1->updateModelMatrix();
    shader->setMat3("normalMat", cube1->getNormalMat());
    shader->setMat4("model", cube1->getModel());
    shader->setFloat("material.shininess", 32.0f);
    cube1->draw(*shader);
    // backpack
    shader->setMat3("normalMat", backpack->getNormalMat());
    shader->setMat4("model", backpack->getModel());
    shader->setFloat("material.shininess", 64.0f);
    backpack->Draw(*shader);


    // draw skybox
    skyboxShader->use();
    view = glm::mat4(glm::mat3(camera.GetViewMatrix()));
    skyboxShader->setMat4("view", view);
    skyboxShader->setMat4("projection", projection);
    skybox->draw(*skyboxShader);

}

void FirstScene::destroyObjects()
{
    delete(shader);
    delete(skyboxShader);
    delete(cube1);
    delete(backpack);
    delete(skybox);
}