# rosmsg Non-ASCII

A minimal demonstration of rostopic breaking on non-ascii character comments in
.msg files.

# To Run

1. Build the package non_ascii_msgs. Note that compilation succeeds with no
    warnings or errors.
2. Run the executable non_ascii_msgs talker, which publishes the message
    generated from msg/Test.msg on the topic /test. Note that the node publishes
    the message with no warnings or errors.

    $ rosrun non_ascii_msgs talker

3. Attempt to echo the topic with rostopic.

    $ rostopic echo /test

rostopic emits a Python stacktrace and dies. Example stacktrace:

    Traceback (most recent call last):
      File "/opt/ros/hydro/bin/rostopic", line 35, in <module>
        rostopic.rostopicmain()
      File "/opt/ros/hydro/lib/python2.7/dist-packages/rostopic/__init__.py", line 1667, in rostopicmain
        _rostopic_cmd_echo(argv)
      File "/opt/ros/hydro/lib/python2.7/dist-packages/rostopic/__init__.py", line 1027, in _rostopic_cmd_echo
        _rostopic_echo(topic, callback_echo, bag_file=options.bag)
      File "/opt/ros/hydro/lib/python2.7/dist-packages/rostopic/__init__.py", line 676, in _rostopic_echo
        msg_class, real_topic, msg_eval = get_topic_class(topic, blocking=True)
      File "/opt/ros/hydro/lib/python2.7/dist-packages/rostopic/__init__.py", line 355, in get_topic_class
        msg_class = roslib.message.get_message_class(topic_type)
      File "/opt/ros/hydro/lib/python2.7/dist-packages/roslib/message.py", line 99, in get_message_class
        cls = genpy.message.get_message_class(message_type, reload_on_error=reload_on_error)
      File "/opt/ros/hydro/lib/python2.7/dist-packages/genpy/message.py", line 599, in get_message_class
        cls = _get_message_or_service_class('msg', message_type, reload_on_error=reload_on_error)
      File "/opt/ros/hydro/lib/python2.7/dist-packages/genpy/message.py", line 550, in _get_message_or_service_class
        pypkg = __import__('%s.%s' % (package, type_str))
      File "/home/evenator/code/rosmsg-Non-ASCII/devel/lib/python2.7/dist-packages/non_ascii_msgs/msg/__init__.py", line 1, in <module>
        from ._Test import *
      File "/home/evenator/code/rosmsg-Non-ASCII/devel/lib/python2.7/dist-packages/non_ascii_msgs/msg/_Test.py", line 13
    SyntaxError: Non-ASCII character '\xe2' in file /home/evenator/code/rosmsg-Non-ASCII/devel/lib/python2.7/dist-packages/non_ascii_msgs/msg/_Test.py on line 14, but no encoding declared; see http://www.python.org/peps/pep-0263.html for details
