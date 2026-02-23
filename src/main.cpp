#include <Geode/modify/ProfilePage.hpp>

class $modify(MyProfilePage, ProfilePage) {
    void loadPageFromUserInfo(GJUserScore *score) {
        ProfilePage::loadPageFromUserInfo(score);

        // Only add the badge if the player has creator points
        if (!score->m_creatorPoints) return;

        // Get the menu to add the badge to
        auto *layer = m_mainLayer;
        auto *menu = layer->getChildByIDRecursive("username-menu");
        if (!menu) return;

        auto *creatorBadgeBtn = CCMenuItemSpriteExtra::create(
            cocos2d::CCSprite::createWithSpriteFrameName("GJ_hammerIcon_001.png"),
            this,
            menu_selector(MyProfilePage::onCreatorBadgeBtn)
        );

        creatorBadgeBtn->setID("creator-badge"_spr);
        menu->addChild(creatorBadgeBtn);
        menu->updateLayout();
    };

    void onCreatorBadgeBtn(CCObject *) {
        FLAlertLayer::create(
            "Creator badge!",
            "This is the <cb>creator badge</c>; it is displayed on <cl>players</c> with <cj>creator points</c>!",
            "OK"
        )->show();
    };
};