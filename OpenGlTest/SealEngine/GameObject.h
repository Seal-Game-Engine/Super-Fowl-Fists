#pragma once
#include <vector>
#include <memory>
#include <string>
#include <array>

#include "Object.h"
#include "MonoBehaviour.h"
#include "Vector3.h"
#include "Transform.h"
class Player;

namespace SealEngine {
    class GameObject : public Object {
    public:
        GameObject();
        GameObject(const std::string& name, const std::string& tag = "Untagged");
        GameObject(const std::string& name, const std::string& tag, std::vector<std::shared_ptr<MonoBehaviour>> components);

        GameObject(const GameObject& obj);

        std::vector<std::shared_ptr<MonoBehaviour>> components{};
        //std::vector<MonoBehaviour> components = std::vector<MonoBehaviour>{};
        bool activeInHierarchy();
        bool activeSelf() const;
        bool isStatic = false;
        std::string tag;
        // layer
        // scene
        // sceneCullingMask
        Transform* transform = nullptr;

        // Identifier
        static GameObject Find(std::string name);
        static GameObject* FindWithTag(const std::string& tag);
        static std::vector<GameObject*> FindGameObjectsWithTag(const std::string& tag);
        bool CompareTag(std::string tag);  // done
        void SetActive(bool value);          // done

        // Components
        template<class T, typename std::enable_if_t<std::is_base_of<MonoBehaviour, T>::value, bool> = true>
        T* AddComponent() {
            std::shared_ptr<T> component = std::make_shared<T>();
            component->gameObject = this;
            components.push_back(component);
            return component.get();
        }

        template<class T>
        T* GetComponent() {
            T* component = nullptr;
            for (auto& _component : components) if (component = dynamic_cast<T*>(_component.get())) return component;
            return nullptr;
        }

        template<class T>
        bool TryGetComponent(T*& component) { return GetComponent<T>() != nullptr; }

        template<class T>
        std::vector<T*> GetComponents() {
            std::vector<T*> targetComponents{};
            for (auto& _component : components) if (auto component = dynamic_cast<T*>(_component.get())) targetComponents.emplace_back(component);
            return targetComponents;
        }

#pragma region Todo Functions
        template<class T>
        T GetComponentInParent(bool includeInactive = false) {
            return T();
        }


        template<class T>
        T GetComponentInChild(bool includeInactive = false) {
            return T();
        }

        template<class T>
        std::vector<T> GetComponentsInParent(bool includeInactive = false) {
            return std::vector<T>();

        }

        template<class T>
        std::vector<T> GetComponentsInChild(bool includeInactive = false) {
            return std::vector<T>();
        }
#pragma endregion

    private:
        bool _activeSelf = true;

        virtual GameObject* _Clone() const override { return new GameObject(*this); };
    };
}
