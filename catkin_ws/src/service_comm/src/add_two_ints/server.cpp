#include "server.h"
// ROS
#include <ros/ros.h>

namespace add_two_ints {
/// @brief ROSサービスのAPI
/// この関数をROSに登録して動作させることになる。
/// これ以外で使われないのでラムダ関数にすることもある。
/// 今回はGoogleTestを実施したいので別途関数として定義する。
/// ※内部リンケージするとGoogleTestの実装が不可能になる。
/// @param req リクエストメッセージ
/// @param res レスポンスメッセージ
/// @return 成否
bool
service::api(service_comm::AddTwoInts::Request& req,
             service_comm::AddTwoInts::Response& res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

service::service()
{
  n = std::make_shared<ros::NodeHandle>();
  // 引数が関数ポインタであるためメンバメソッドを渡すことはできない。
  // 通常関数はメモリアドレスが固定だが、メンバメソッドはコンストラクトされないとメモリが確定しない。
  // また、メンバメソッドはthisポインタを経由しないとコールできないため渡すことはできない。
  server = n->advertiseService(add_two_ints::service_name, api);
}

service::~service(){};

}
