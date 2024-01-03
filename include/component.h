#ifndef COMPONENT_H
#define COMPONENT_H

#include "engine.h"

namespace fls_engine
{
    /* GameObject's Component*/
    class Component
    {
    protected:
    public:
        /**
         * @brief the gameObject which this component belongs to
         * 
         */
        GObject *onwer;
        bool isEnabled;
        bool enabled;
        bool started;
        Component();
        Component(GObject &onwer);
        /* below are life circle functions */
        virtual void update() {}
        virtual void updateUI() {}
        virtual void start() {}
        virtual void enable() {}
        virtual void renderUI() {}

        virtual Component *clone() const;
        virtual ~Component() {}
    };
    class CameraComponent : public Component
    {
    protected:
        glm::mat4 projection;

    public:
        float fovy;
        float aspect;
        float near;
        float far;
        CameraComponent(GObject &onwer, float fovy, float aspect, float near, float far);
        /**
         * @brief Get the View matrix
         * 
         * @return glm::mat4 
         */
        glm::mat4 getView();
        /**
         * @brief Set the Projection matrix
         * 
         * @param fovy 
         * @param aspect 
         * @param near 
         * @param far 
         */
        void setProjection(float fovy, float aspect, float near, float far);
        /**
         * @brief Get the Projection matrix
         * 
         * @return glm::mat4 
         */
        glm::mat4 getProjection();
        virtual CameraComponent *clone() const;
        virtual ~CameraComponent() {}
    };
}

#endif