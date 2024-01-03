#ifndef ENGINE_H
#define ENGINE_H


#include <vector>
#include "shader.h"

#include "typedef.h"
#include "gobject.h"
#include "component.h"


namespace fls_engine
{
    class Engine
    {
    private:
        int preTime;
    public:
        /**
         * @brief time between two cycles(ms)
         * 
         */
        int deltaTime;
        std::vector<std::shared_ptr<BaseShader> > shaders;
        ShaderRunner shaderRunner;
        std::shared_ptr<Scene> scene;
        bool shouldRestart;
        /**
         * @brief if true, will print debug info
         * 
         */
        bool stageDebug;
        DevInit devInit;
        UpdateScreen updateScreen;
        FreshScreen freshScreen;
        GetTime getTime;
        
        std::function<std::vector<std::shared_ptr<VertexBundle> > (Engine&,std::vector<std::shared_ptr<VertexBundle> >&)> filterVB;

        /**
         * @brief Construct a new Engine object
         * 
         * @param width screen's width
         * @param height screen's height
         * @param zoomX width's zoom
         * @param zoomY height's zoom
         * @param updateScreen function to updating screen buffer
         * @param freshScreen function to applying screen buffer
         * @param getTime function to getting current time
         */
        Engine(int width, int height, int zoomX, int zoomY,UpdateScreen updateScreen, FreshScreen freshScreen,GetTime getTime);
        /**
         * @brief Run the Engine object
         * 
         */
        void run();
        /**
         * @brief add shader object
         * 
         * @param shader shader object
         * @return unsigned int shader's id. can be used to specify which shader to shading a vertex bundle
         */
        unsigned int addShader(std::shared_ptr<BaseShader> shader);
        
        /**
         * @brief get camera component
         * 
         * @return std::shared_ptr<CameraComponent> camera component
         */
        std::shared_ptr<CameraComponent> getCamera();
        
        /**
         * @brief load scene. can be call in any life cycle function like update(), start(), 
         * and will be applied at the begin of next cycle
         * 
         * @param scene the scene to load
         */
        void loadScene(std::shared_ptr<Scene> scene);
        
        /**
         * @brief just a filter function to filter vertex bundles, which can improve the efficiency of shading. enable it by set it to filterVB
         * 
         * @param engine 
         * @param vbs 
         * @return std::vector<std::shared_ptr<VertexBundle> > 
         */
        static std::vector<std::shared_ptr<VertexBundle> > filterBlockVB(Engine& engine,std::vector<std::shared_ptr<VertexBundle> >& vbs);
    };
}

#endif