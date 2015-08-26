#GBAlipay<br>
* 介绍：<br>
  * 最近的o2o和p2p的市场比较活出现了很多的电商类的app 既然提到了电商那就不可避免的谈到支付功能，谈到支付就不得不说第三方支付里面的三巨头之一的支付宝<br>
  * 支付宝的官方文档写的还是不错的最起码比微信的要强很多，但是还是不够精简要是能做到一句话调用就好了,我就对他的代码做了一些简单的封装<br>
  * 代码里只需要简单的调用一句话就可以实现这个支付功能<br>
#如何使用

  * 首先将GBAlipay文件导入到工程里面<br>
  * 点击项目名称,点击“Build Phases”选项卡,在“Link Binary with Librarles” 选项中,新增“AlipaySDK.framework”和“SystemConfiguration.framework” 两个系统库文件。如果项目中已有这两个库文件,可不必再增加<br>
  * 点击项目名称,点击“Build Settings”选项卡,在搜索框中,以关键字“search” 搜索,对“Header Search Paths”增加头文件路径:“$(SRCROOT)/项目名称/GBAlipay/Alipay”（注意：不包括引号，如果不是放到项目根目录下，请在项目名称后面加上相应的目录名）<br>
  * 在本头文件中设置kPartnerID、kSellerAccount、kNotifyURL、kAppScheme和kPrivateKey的值（所有的值在支付宝回复的邮件里面：注意，建议除appScheme以外的字段都从服务器请求）<br>
  * 点击项目名称,点击“Info”选项卡，在URL types里面添加一项，Identifier可以不填，URL schemes必须和appScheme的值相同，用于支付宝处理回到应用的事件；<br>
  * 在需要调用支付的界面直接包含头文件#import "GBAlipayConfig.h"，一句话调用方法即可，另外接收回调结果复制以下代码：<br>
   ```
   viewDidLoad里面添加监听：
   [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(dealAlipayResult:) name:@"alipayResult" object:nil];
//移除监听
     -(void)dealloc{
     
     [[NSNotificationCenter defaultCenter] removeObserver:self];
     
     }
//监听处理事件
 -(void)dealAlipayResult:(NSNotification*)notification{
 NSString*result=notification.object;
 
 if([result isEqualToString:@"9000"]){
 
      NSLog(@"支付成功");
 
 }else{
 
      NSLog(@"支付失败");
 }

 
 }
 
 *7.别忘了在AppDelegate中处理事件回调（可直接复制下面内容）：
 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
 //如果极简 SDK 不可用,会跳转支付宝钱包进行支付,需要将支付宝钱包的支付结果回传给 SDK if ([url.host isEqualToString:@"safepay"]) {
 [[AlipaySDK defaultService] processOrderWithPaymentResult:url standbyCallback:^(NSDictionary *resultDic) {
 NSLog(@"result = %@",resultDic);
 //支付结果
 [[NSNotificationCenter defaultCenter]postNotificationName:@"alipayResult" object:[resultDic objectForKey:@"resultStatus"]];
 }];
 if ([url.host isEqualToString:@"platformapi"]){//支付宝钱包快登授权返回 authCode
 [[AlipaySDK defaultService] processAuthResult:url standbyCallback:^(NSDictionary *resultDic) {
 NSLog(@"result = %@",resultDic);
 }];
 }
 return YES;
 }
 *
 */
  ```
#效果展示：<br>
##网页<br>
![image1](https://github.com/mokey1422/gifResource/blob/master/2015-08-26%2010_08_05.gif)
##客户端<br>

>>![image2](https://github.com/mokey1422/gifResource/blob/master/alipay.gif)
