#pragma once
#include <vector>
#include <string>
#include <array>

using objectId = int;
using Vector3 = float; //placeholder for Transfomr
using MonoBehaviour = float; //placeholder for MonoBehavior

class GameObject {
  GameObject();
  GameObject(std::string name);
  GameObject(std::string name, MonoBehaviour);

 public:
  bool activeInHierachy;
  bool activeSelf;
  bool isStatic;
  // layer
  // scene
  // sceneCullingMask
  std::string tag;
  std::string name;
  // transform;

  // Properties
  static void Instantiate(objectId, Vector3, std::vector<MonoBehaviour>);
  static void Destroy();
  static void DontDestroyOnLoad(GameObject target);


  // Identifier
  static void Find(objectId);
  static GameObject FindWithTag(std::string);
  static std::vector<GameObject> FindGameObjectsWithTag(std::string);
  void GetInstanceID(objectId);
  bool CompareTag(std::string);
  void SetActive(bool);
  std::string ToString();
  template <typename T>
  static T FindObjectOfType();
  template <typename T>
  static std::vector<T> FindObjectsOfType();



  // Components
  template <typename T>
  void AddComponenet(objectId, std::vector<MonoBehaviour>, T);
  template <typename T>
  void GetComponent(objectId, T);
  template <typename T>
  void GetComponentInParent(T);
  template <typename T>
  void GetComponentInChild(T);
  template <typename T>
  void TryGetComponent(T);
};
