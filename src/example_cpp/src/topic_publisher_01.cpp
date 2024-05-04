#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class TopicPublisher01:public rclcpp::Node
{
    public:
        TopicPublisher01(std::string name):Node(name)
        {
            RCLCPP_INFO(this->get_logger(), "%s node has started.", name.c_str());
        }

    private:

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TopicPublisher01>("topic_publisher_01");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}