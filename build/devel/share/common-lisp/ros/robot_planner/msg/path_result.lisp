; Auto-generated. Do not edit!


(cl:in-package robot_planner-msg)


;//! \htmlinclude path_result.msg.html

(cl:defclass <path_result> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type (cl:vector robot_planner-msg:data_result)
   :initform (cl:make-array 0 :element-type 'robot_planner-msg:data_result :initial-element (cl:make-instance 'robot_planner-msg:data_result))))
)

(cl:defclass path_result (<path_result>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <path_result>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'path_result)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_planner-msg:<path_result> is deprecated: use robot_planner-msg:path_result instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <path_result>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_planner-msg:result-val is deprecated.  Use robot_planner-msg:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <path_result>) ostream)
  "Serializes a message object of type '<path_result>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'result))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <path_result>) istream)
  "Deserializes a message object of type '<path_result>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'result) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'result)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'robot_planner-msg:data_result))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<path_result>)))
  "Returns string type for a message object of type '<path_result>"
  "robot_planner/path_result")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'path_result)))
  "Returns string type for a message object of type 'path_result"
  "robot_planner/path_result")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<path_result>)))
  "Returns md5sum for a message object of type '<path_result>"
  "05c8d58b6be9147bdddc88d0fd92da98")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'path_result)))
  "Returns md5sum for a message object of type 'path_result"
  "05c8d58b6be9147bdddc88d0fd92da98")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<path_result>)))
  "Returns full string definition for message of type '<path_result>"
  (cl:format cl:nil "data_result[] result~%================================================================================~%MSG: robot_planner/data_result~%float32 cx~%float32 cy~%float32 cyaw~%float32 ck ~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'path_result)))
  "Returns full string definition for message of type 'path_result"
  (cl:format cl:nil "data_result[] result~%================================================================================~%MSG: robot_planner/data_result~%float32 cx~%float32 cy~%float32 cyaw~%float32 ck ~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <path_result>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'result) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <path_result>))
  "Converts a ROS message object to a list"
  (cl:list 'path_result
    (cl:cons ':result (result msg))
))
