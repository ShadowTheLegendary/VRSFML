#include <SFML/Graphics/RenderTexture.hpp>

#include <catch2/catch_test_macros.hpp>

#include <WindowUtil.hpp>
#include <type_traits>

TEST_CASE("[Graphics] sf::RenderTexture", runDisplayTests())
{
    SECTION("Type traits")
    {
        STATIC_CHECK(!std::is_copy_constructible_v<sf::RenderTexture>);
        STATIC_CHECK(!std::is_copy_assignable_v<sf::RenderTexture>);
        STATIC_CHECK(std::is_nothrow_move_constructible_v<sf::RenderTexture>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<sf::RenderTexture>);
    }

    SECTION("Construction")
    {
        const sf::RenderTexture renderTexture;
        CHECK(!renderTexture.isSmooth());
        CHECK(!renderTexture.isRepeated());
        CHECK(renderTexture.getSize() == sf::Vector2u(0, 0));
    }

    SECTION("create()")
    {
        CHECK(!sf::RenderTexture::create({1'000'000, 1'000'000}));

        CHECK(sf::RenderTexture::create({100, 100}, sf::ContextSettings{8 /* depthBits */, 0 /* stencilBits */}));
        CHECK(sf::RenderTexture::create({100, 100}, sf::ContextSettings{0 /* depthBits */, 8 /* stencilBits */}));

        const auto renderTexture = sf::RenderTexture::create({360, 480}).value();
        CHECK(renderTexture.getSize() == sf::Vector2u(360, 480));
        CHECK(!renderTexture.isSmooth());
        CHECK(!renderTexture.isRepeated());
        CHECK(!renderTexture.isSrgb());

        const auto& texture = renderTexture.getTexture();
        CHECK(texture.getSize() == sf::Vector2u(360, 480));
        CHECK(!texture.isSmooth());
        CHECK(!texture.isSrgb());
        CHECK(!texture.isRepeated());
        CHECK(texture.getNativeHandle() != 0);
    }

    SECTION("resize()")
    {
        sf::RenderTexture renderTexture;
        CHECK(!renderTexture.resize({1'000'000, 1'000'000}));
        CHECK(renderTexture.resize({480, 360}));
        CHECK(!renderTexture.isSmooth());
        CHECK(!renderTexture.isRepeated());
        CHECK(renderTexture.getSize() == sf::Vector2u(480, 360));
        CHECK(!renderTexture.isSrgb());
        CHECK(renderTexture.resize({360, 480}));
        CHECK(renderTexture.getSize() == sf::Vector2u(360, 480));
        CHECK(renderTexture.resize({100, 100}, sf::ContextSettings{8 /* depthBits */, 0 /* stencilBits */}));
        CHECK(renderTexture.resize({100, 100}, sf::ContextSettings{0 /* depthBits */, 8 /* stencilBits */}));
    }

    SECTION("getMaximumAntialiasingLevel()")
    {
        CHECK(sf::RenderTexture::getMaximumAntialiasingLevel() <= 64);
    }

    SECTION("Set/get smooth")
    {
        auto renderTexture = sf::RenderTexture::create({64, 64}).value();
        renderTexture.setSmooth(true);
        CHECK(renderTexture.isSmooth());
    }

    SECTION("Set/get repeated")
    {
        auto renderTexture = sf::RenderTexture::create({64, 64}).value();
        renderTexture.setRepeated(true);
        CHECK(renderTexture.isRepeated());
    }

    SECTION("generateMipmap()")
    {
        auto renderTexture = sf::RenderTexture::create({64, 64}).value();
        CHECK(renderTexture.generateMipmap());
    }

    SECTION("setActive()")
    {
        auto renderTexture = sf::RenderTexture::create({64, 64}).value();
        CHECK(renderTexture.setActive());
        CHECK(renderTexture.setActive(false));
        CHECK(renderTexture.setActive(true));
    }

    SECTION("getTexture()")
    {
        const auto renderTexture = sf::RenderTexture::create({64, 64}).value();
        CHECK(renderTexture.getTexture().getSize() == sf::Vector2u(64, 64));
    }
}
