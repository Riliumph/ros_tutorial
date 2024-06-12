// STL
#include <memory>
// ROS
#include <ros/ros.h>
// DB
#include <pqxx/pqxx>

int
main(int argc, char** argv)
{
  ros::init(argc, argv, "postgres");
  try {
    auto db_conn = std::make_unique<pqxx::connection>("host=db_server"
                                                      " port=5432"
                                                      " dbname=postgres"
                                                      " user=postgres"
                                                      " password=postgres");
    pqxx::work transactor(*db_conn);
    auto query = "select * from student";
    pqxx::result res(transactor.exec(query));
    transactor.commit();
    // 結果の表示
    for (auto row : res) {
      std::cout << "student_id = " << row["student_id"].as<int>()
                << ", Name = " << row["name"].as<std::string>() << std::endl;
    }
  } catch (const pqxx::sql_error& e) {
    std::cerr << e.what() << " : SQL->" << e.query() << std::endl;
  } catch (const pqxx::usage_error& e) {
    std::cerr << e.what() << std::endl;
  }
}
