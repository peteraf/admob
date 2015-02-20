#import "LDAdService.h"


@interface LDMoPubSettings : NSObject<LDAdServiceSettings>
/**AdUnits**/
@property (nonatomic, strong) NSString * banner;
@property (nonatomic, strong) NSString * bannerIpad;
@property (nonatomic, strong) NSString * interstitial;
@property (nonatomic, strong) NSString * interstitialIpad;

@end

@interface LDAdServiceMoPub : LDAdService
@property (nonatomic, strong) LDMoPubSettings * settings;

-(instancetype) init;

@end
