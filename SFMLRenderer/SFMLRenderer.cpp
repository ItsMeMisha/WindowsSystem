#include "SFMLRenderer.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <string>

SFMLRenderer* SFMLRenderer::renderer = nullptr;

SFMLRenderer& SFMLRenderer::getRenderer(const Point& size, const char* appName) {
  if (renderer == nullptr)
    renderer = new SFMLRenderer(size, appName);
  return *renderer;
}

/*
void SFMLRenderer::renderWindow(const Window* window) {

}
*/
void SFMLRenderer::renderRectangle(const Point& pos, const Point& size, const Color& color) {
  sf::RectangleShape rect;
  rect.setPosition(pos.x, pos.y);
  rect.setSize({(float)size.x, (float)size.y});
  rect.setFillColor({color.r, color.g, color.b});
  rootWin.draw(rect);
}

void SFMLRenderer::renderResult() {
  rootWin.display();
}

void SFMLRenderer::clear() {
  rootWin.clear();
}

void SFMLRenderer::start() {
    targetsToRender.push(rootWin);
    renderingOffsets.push({0, 0});
    renderResult();
}

void SFMLRenderer::stop() {
    //delete rootWin;
}

sf::RenderWindow* SFMLRenderer::getRootWindow() {
    return &rootWin;
}

bool SFMLRenderer::isRunning() {
    return rootWin.isOpen();
}

void SFMLRenderer::pushTarget(const Vector2d& size, const Vector2d& offset) {
    auto* sf_texture = new sf::RenderTexture();
    sf_texture->create(size.x, size.y);
    sf_texture->clear(sf::Color::White);
    targetsToRender.push(sf_texture);
    renderingOffsets.push(offset);
}

void SFMLRenderer::popTargetToDisplay(const Vector2d& pos) {
    renderingOffsets.pop();

    auto flushed_texture = static_cast<sf::RenderTexture*>(targetsToRender.top());
    targetsToRender.pop();
    flushed_texture->display();

    auto sf_sprite = sf::Sprite();
    sf_sprite.setTexture(flushed_texture->getTexture());
    sf_sprite.setPosition(to_sfVect2f(pos));

    targetsToRender.top()->draw(sf_sprite);
    delete flushed_texture;
}

void SFMLRenderer::renderTexture(const Vector2d& pos, 
                                     const char* image_name) {
    auto sf_texture = sf::Texture();
    sf_texture.loadFromFile(image_name);
    auto sf_sprite = sf::Sprite();
    sf_sprite.setTexture(sf_texture);
    sf_sprite.setPosition(to_sfVect2f(pos));
    targetsToRender.top()->draw(sf_sprite);
    
}

void SFMLRenderer::renderTexture(const Vector2d& pos, 
                                     const sf::Texture& sf_texture) {
    auto sf_sprite = sf::Sprite();
    sf_sprite.setTexture(sf_texture);
    sf_sprite.setPosition(to_sfVect2f(pos));
    targetsToRender.top()->draw(sf_sprite);
    
}

void SFMLRenderer::renderText(const std::string& text, const Vector2d& pos, size_t size) {
    auto sf_text = sf::Text();
    auto sf_font = sf::Font();

    sf_font.loadFromFile("Misc/SanFrancisco.ttf");
    sf_text.setString(sf::String::fromUtf8(text.begin(), text.end()));
    sf_text.setFont(sf_font);
    sf_text.setCharacterSize(size);
    sf_text.setFillColor(sf::Color::Black);

    sf_text.setPosition(to_sfVect2f(pos - draw_offsets.top()));
    targetsToRender.top()->draw(sf_text);
}

void SFMLRenderer::renderBitmap(const vector<uint8_t>& image,
                                    const Vector2d& pos, const Vector2d& size) {
    auto sf_texture = sf::Texture();
    sf_texture.create(size.x, size.y);
    sf_texture.update(image.data());

    renderTexture(pos, sf_texture);
}

void SFMLRenderer::renderLine(const Vector2d& start, const Vector2d& finish) {
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = to_sfVect2f(start);
    line[0].color = sf::Color::Black;
    line[1].position = to_sfVect2f(finish);
    line[1].color = sf::Color::Black;
    targetsToRender.top()->draw(line);
}

void SFMLRenderer::renderBox(const Vector2d& pos, const Vector2d& size) {
    renderLine({pos.x, pos.y + size.y}, {pos.x + size.x, pos.y + size.y});
    renderLine(pos, {pos.x + size.x, pos.y}); 
    renderLine(pos, {pos.x, pos.y + size.y});
    renderLine({pos.x + size.x, pos.y }, {pos.x + size.x, pos.y + size.y});
}

SFMLRenderer::SFMLRenderer(const Point& size, const char* appName) : 
  rootWin(sf::RenderWindow(sf::VideoMode(size.x, size.y), appName)) {}

Vector2d SFMLRenderer::eff_pos(const Vector2d& pos) {
    return pos - renderingOffsets.top(); 
}
