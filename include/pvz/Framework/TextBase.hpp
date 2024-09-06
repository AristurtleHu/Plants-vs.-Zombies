#ifndef TEXTBASE_H__
#define TEXTBASE_H__

#include <iostream>
#include <set>

#include "pvz/utils.hpp"

class TextBase {
public:
  TextBase(int x, int y, const std::string& text = "", double colorR = 0, double colorG = 0, double colorB = 0, bool m_centering = true);
  TextBase(const TextBase& other) = delete;
  TextBase(TextBase&& other) = delete;
  TextBase& operator=(const TextBase& other) = delete;
  TextBase& operator=(TextBase&& other) = delete;
  virtual ~TextBase();


  int GetX() const;
  int GetY() const;

  void MoveTo(int x, int y); 
  void SetText(std::string text);
  
  // Sets color R, G, B in range [0, 1].
  void SetColor(double r, double g, double b);
  
  void SetCentering(bool centering);

  friend class GameManager;

private:
  int m_x;
  int m_y;

  std::string m_text;

  double m_colorR;
  double m_colorG;
  double m_colorB;

  bool m_centering;

private:
  template<typename Func>
  static void DisplayAllTexts(Func displayFunc) {
    for (auto& obj : TextBase::s_allTexts) {
      displayFunc(obj->m_x, obj->m_y, obj->m_text, obj->m_colorR, obj->m_colorG, obj->m_colorB, obj->m_centering);
    }
  }

  static std::set<TextBase*> s_allTexts;

};


#endif // !TEXTBASE_H__
