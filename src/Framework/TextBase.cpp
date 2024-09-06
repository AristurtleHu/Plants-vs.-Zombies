#include "pvz/Framework/TextBase.hpp"
#include "pvz/Framework/GameManager.hpp"

// Initialize static s_allTexts to an empty set.
std::set<TextBase*> TextBase::s_allTexts{};

TextBase::TextBase(int x, int y, const std::string& text, double colorR, double colorG, double colorB, bool centering)
  : m_x(x), m_y(y), m_text(text), m_colorR(colorR), m_colorG(colorG), m_colorB(colorB), m_centering(centering){
  s_allTexts.insert(this);
}

TextBase::~TextBase() {
  s_allTexts.erase(this);
}

int TextBase::GetX() const {
  return m_x;
}

int TextBase::GetY() const {
  return m_y;
}


void TextBase::MoveTo(int x, int y) {
  m_x = x;
  m_y = y;
}

void TextBase::SetText(std::string text) {
  m_text = text;
}

void TextBase::SetColor(double r, double g, double b) {
  m_colorR = r;
  m_colorG = g;
  m_colorB = b;
}

void TextBase::SetCentering(bool centering) {
  m_centering = centering;
}



