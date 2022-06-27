
(cl:in-package :asdf)

(defsystem "robot_planner-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "data_result" :depends-on ("_package_data_result"))
    (:file "_package_data_result" :depends-on ("_package"))
    (:file "path_result" :depends-on ("_package_path_result"))
    (:file "_package_path_result" :depends-on ("_package"))
  ))