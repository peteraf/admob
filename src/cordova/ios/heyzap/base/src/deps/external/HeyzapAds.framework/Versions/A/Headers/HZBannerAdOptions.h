//
//  HZBannerAdOptions.h
//  Heyzap
//
//  Created by Maximilian Tagher on 3/11/15.
//  Copyright (c) 2015 Heyzap. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * The size to use for Facebook banners
 */
typedef NS_ENUM(NSUInteger, HZFacebookBannerSize
) {
/**
 *  A fixed size 320x50 pt banner. Corresponds to kFBAdSize320x50.
 */
HZFacebookBannerSize320x50 __attribute__((deprecated("Facebook has deprecated the 320x50 size."))),
/**
 *  A banner 50 pts in height whose width expands to fill its containing view. Corresponds to kFBAdSizeHeight50Banner.
 *  **Default value** for Facebook banners.
 */
HZFacebookBannerSizeFlexibleWidthHeight50,
/**
 *  A banner 90 pts in height whose width expands to fill its containing view. Corresponds to kFBAdSizeHeight90Banner.
 */
HZFacebookBannerSizeFlexibleWidthHeight90,
};

/**
 *  The size to use for AdMob banners. NB: Some of AdMob's banner heights vary by iPad/iPhone.
 */
typedef NS_ENUM(NSUInteger, HZAdMobBannerSize
){
/**
 *  An ad size that spans the full width of the application in portrait orientation. The height is
 *  typically 50 pixels on an iPhone/iPod UI, and 90 pixels tall on an iPad UI. Corresponds to kGADAdSizeSmartBannerPortrait.
 *
 *  This is the **default size**
 */
HZAdMobBannerSizeFlexibleWidthPortrait,
/**
 *  An ad size that spans the full width of the application in landscape orientation. The height is
 *  typically 32 pixels on an iPhone/iPod UI, and 90 pixels tall on an iPad UI. Corresponds to kGADAdSizeSmartBannerLandscape.
 */
HZAdMobBannerSizeFlexibleWidthLandscape,
/**
 *  iPhone and iPod Touch sized banner. Typically 320x50. Corresponds to kGADAdSizeBanner.
 */
HZAdMobBannerSizeBanner,
/**
 *  Taller version of HZAdMobBannerSizeBanner. Typically 320x100. Corresponds to kGADAdSizeLargeBanner.
 */
HZAdMobBannerSizeLargeBanner,
/**
 *  Leaderboard size for the iPad. Typically 728x90. Corresponds to kGADAdSizeLeaderboard.
 */
HZAdMobBannerSizeLeaderboard,
/**
 *  Full Banner size for the iPad (especially in a UIPopoverController or in
 *  UIModalPresentationFormSheet). Typically 468x60. Corresponds to kGADAdSizeFullBanner.
 */
HZAdMobBannerSizeFullBanner,
};

/**
 * The size to use for Inmobi banners
 */
typedef NS_ENUM(NSUInteger, HZInmobiBannerSize
) {
HZInmobiBannerSize320x50,
HZInmobiBannerSize320x48,
HZInmobiBannerSize300x250,
HZInmobiBannerSize120x600,
HZInmobiBannerSize468x60,
HZInmobiBannerSize728x90,
HZInmobiBannerSize1024x768
};

@interface HZBannerAdOptions : NSObject <NSCopying>

/**
 *  The size to use for Facebook Audience Network banners. Defaults to HZFacebookBannerSizeFlexibleWidthHeight50.
 */
    @property(nonatomic) HZFacebookBannerSize facebookBannerSize;

/**
 *  The size to use for Admob banners.
 */
    @property(nonatomic) HZAdMobBannerSize admobBannerSize;

/**
 *  The size to use for Inmobi banners.
 */
    @property(nonatomic) HZInmobiBannerSize inmobiBannerSize;

/**
 *  The view controller to present the ad from.
 *
 *  This property is optional. If not set, it defaults to the root view controller of the application.
 *
 *  @note Setting this property doesn't change where the actual banner (a `UIView`) is placed. For Heyzap Exchange banners, the width of this property will determine the width of a flexible-width banner.
 */
    @property(nonatomic, weak) UIViewController *presentingViewController;

/**
 *  An identifier for the location of the ad, which you can use to disable the ad from your dashboard. If not specified the tag "default" is always used.
 */
    @property(nonatomic, strong) NSString *tag;

/**
 *  Banner ads have some internal retry logic, to prevent show failures caused by bad network connectivity. Set this time interval to restrict how many seconds Heyzap spends trying to fetch banner ads. This value will only be considered after an initial failure; for instance, a fetchTimeout of 0 will not stop the initial fetch, but it will stop all retries.
 *
 *  @b Default: @c DBL_MAX (no timeout).
 *
 *  @b Minimum: 0
 *
 *  @note Setting this value too low will prevent Heyzap from retrying at all. Give time for slow network requests in this value if you wish to allow Heyzap to retry at least a couple of times before failing (i.e.: at least 60 seconds).
 */
    @property(nonatomic) NSTimeInterval fetchTimeout;

@end