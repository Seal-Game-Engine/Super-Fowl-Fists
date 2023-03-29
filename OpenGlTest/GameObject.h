#pragma once
#include <vector>
#include <string>
#include <array>

#include "Object.h"
#include "MonoBehaviour.h"
#include "Vector3.h"

namespace SealEngine {
class GameObject : public Object {
  GameObject();
  GameObject(Object name);
  GameObject(Object name, MonoBehaviour);

 public:
  bool activeInHierarchy;
  bool activeSelf() const;
  bool isStatic;
  std::string tag;
  // layer
  // scene
  // sceneCullingMask
  // transform;

  // Identifier
  static void Find(Object instanceId);
  static GameObject FindWithTag(std::string);
  static std::vector<GameObject> FindGameObjectsWithTag(std::string);
  void GetInstanceID(Object instanceId);
  bool CompareTag(std::string);  // done
  void SetActive(bool);          // done

  // Components
  template <class T>
  T AddComponent();
  template <class T>
  T GetComponent();
  template <class T>
  void GetComponentInParent(T);  //
  template <class T>
  void GetComponentInChild(T);  //
  template <class T>
  void TryGetComponent(T);  //

 private:
  bool _activeSelf;
};
}  // namespace SealEngine
