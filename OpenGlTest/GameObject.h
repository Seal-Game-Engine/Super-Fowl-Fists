#pragma once
#include <__tuple>
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
  bool activeInHierarchy;
  bool activeSelf() const;
  bool isStatic;
  // layer
  // scene
  // sceneCullingMask
  std::string tag;
  std::string name;
  // transform;

  // Properties
  static void Instantiate(objectId, Vector3, std::vector<MonoBehaviour>);
  static void Destroy();//
  static void DontDestroyOnLoad(GameObject target);

  // Identifier
  static void Find(objectId);
  static GameObject FindWithTag(std::string);
  static std::vector<GameObject> FindGameObjectsWithTag(std::string);
  void GetInstanceID(objectId);
  bool CompareTag(std::string);     //done
  void SetActive(bool);             //done
  std::string ToString();
  template <class T>
  static T FindObjectOfType();
  template <class T>
  static std::vector<T> FindObjectsOfType();



  // Components
  template <class T>
  T AddComponent();
  template <class T>
  T GetComponent();
  template <class T>
  void GetComponentInParent(T);//
  template <class T>
  void GetComponentInChild(T);//
  template <class T>
  void TryGetComponent(T);//

  private:
    bool _activeSelf;
};
