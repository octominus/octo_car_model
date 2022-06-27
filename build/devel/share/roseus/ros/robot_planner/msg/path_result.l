;; Auto-generated. Do not edit!


(when (boundp 'robot_planner::path_result)
  (if (not (find-package "ROBOT_PLANNER"))
    (make-package "ROBOT_PLANNER"))
  (shadow 'path_result (find-package "ROBOT_PLANNER")))
(unless (find-package "ROBOT_PLANNER::PATH_RESULT")
  (make-package "ROBOT_PLANNER::PATH_RESULT"))

(in-package "ROS")
;;//! \htmlinclude path_result.msg.html


(defclass robot_planner::path_result
  :super ros::object
  :slots (_result ))

(defmethod robot_planner::path_result
  (:init
   (&key
    ((:result __result) (let (r) (dotimes (i 0) (push (instance robot_planner::data_result :init) r)) r))
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&rest __result)
   (if (keywordp (car __result))
       (send* _result __result)
     (progn
       (if __result (setq _result (car __result)))
       _result)))
  (:serialization-length
   ()
   (+
    ;; robot_planner/data_result[] _result
    (apply #'+ (send-all _result :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; robot_planner/data_result[] _result
     (write-long (length _result) s)
     (dolist (elem _result)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; robot_planner/data_result[] _result
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _result (let (r) (dotimes (i n) (push (instance robot_planner::data_result :init) r)) r))
     (dolist (elem- _result)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get robot_planner::path_result :md5sum-) "05c8d58b6be9147bdddc88d0fd92da98")
(setf (get robot_planner::path_result :datatype-) "robot_planner/path_result")
(setf (get robot_planner::path_result :definition-)
      "data_result[] result
================================================================================
MSG: robot_planner/data_result
float32 cx
float32 cy
float32 cyaw
float32 ck 
")



(provide :robot_planner/path_result "05c8d58b6be9147bdddc88d0fd92da98")


