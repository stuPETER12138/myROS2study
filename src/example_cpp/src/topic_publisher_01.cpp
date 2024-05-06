#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class TopicPublisher01:public rclcpp::Node
{
    public:
        TopicPublisher01(std::string name):Node(name)
        {
            RCLCPP_INFO(this->get_logger(), "%s node has started.", name.c_str());
            command_publisher_ = this->create_publisher<std_msgs::msg::String>("command", 10); 
        }

    private:
        rclcpp::Publisher<std_msgs:msg::String>::SharedPtr command_publisher_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TopicPublisher01>("topic_publisher_01");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}