;; Auto-generated. Do not edit!


(when (boundp 'robot_planner::data_result)
  (if (not (find-package "ROBOT_PLANNER"))
    (make-package "ROBOT_PLANNER"))
  (shadow 'data_result (find-package "ROBOT_PLANNER")))
(unless (find-package "ROBOT_PLANNER::DATA_RESULT")
  (make-package "ROBOT_PLANNER::DATA_RESULT"))

(in-package "ROS")
;;//! \htmlinclude data_result.msg.html


(defclass robot_planner::data_result
  :super ros::object
  :slots (_cx _cy _cyaw _ck ))

(defmethod robot_planner::data_result
  (:init
   (&key
    ((:cx __cx) 0.0)
    ((:cy __cy) 0.0)
    ((:cyaw __cyaw) 0.0)
    ((:ck __ck) 0.0)
    )
   (send-super :init)
   (setq _cx (float __cx))
   (setq _cy (float __cy))
   (setq _cyaw (float __cyaw))
   (setq _ck (float __ck))
   self)
  (:cx
   (&optional __cx)
   (if __cx (setq _cx __cx)) _cx)
  (:cy
   (&optional __cy)
   (if __cy (setq _cy __cy)) _cy)
  (:cyaw
   (&optional __cyaw)
   (if __cyaw (setq _cyaw __cyaw)) _cyaw)
  (:ck
   (&optional __ck)
   (if __ck (setq _ck __ck)) _ck)
  (:serialization-length
   ()
   (+
    ;; float32 _cx
    4
    ;; float32 _cy
    4
    ;; float32 _cyaw
    4
    ;; float32 _ck
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _cx
       (sys::poke _cx (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _cy
       (sys::poke _cy (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _cyaw
       (sys::poke _cyaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _ck
       (sys::poke _ck (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _cx
     (setq _cx (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _cy
     (setq _cy (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _cyaw
     (setq _cyaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _ck
     (setq _ck (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get robot_planner::data_result :md5sum-) "ac72c95b5c686c44d788b60e9209fa35")
(setf (get robot_planner::data_result :datatype-) "robot_planner/data_result")
(setf (get robot_planner::data_result :definition-)
      "float32 cx
float32 cy
float32 cyaw
float32 ck 
")



(provide :robot_planner/data_result "ac72c95b5c686c44d788b60e9209fa35")


