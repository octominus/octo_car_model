; Auto-generated. Do not edit!


(cl:in-package robot_planner-msg)


;//! \htmlinclude data_result.msg.html

(cl:defclass <data_result> (roslisp-msg-protocol:ros-message)
  ((cx
    :reader cx
    :initarg :cx
    :type cl:float
    :initform 0.0)
   (cy
    :reader cy
    :initarg :cy
    :type cl:float
    :initform 0.0)
   (cyaw
    :reader cyaw
    :initarg :cyaw
    :type cl:float
    :initform 0.0)
   (ck
    :reader ck
    :initarg :ck
    :type cl:float
    :initform 0.0))
)

(cl:defclass data_result (<data_result>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <data_result>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'data_result)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_planner-msg:<data_result> is deprecated: use robot_planner-msg:data_result instead.")))

(cl:ensure-generic-function 'cx-val :lambda-list '(m))
(cl:defmethod cx-val ((m <data_result>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_planner-msg:cx-val is deprecated.  Use robot_planner-msg:cx instead.")
  (cx m))

(cl:ensure-generic-function 'cy-val :lambda-list '(m))
(cl:defmethod cy-val ((m <data_result>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_planner-msg:cy-val is deprecated.  Use robot_planner-msg:cy instead.")
  (cy m))

(cl:ensure-generic-function 'cyaw-val :lambda-list '(m))
(cl:defmethod cyaw-val ((m <data_result>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_planner-msg:cyaw-val is deprecated.  Use robot_planner-msg:cyaw instead.")
  (cyaw m))

(cl:ensure-generic-function 'ck-val :lambda-list '(m))
(cl:defmethod ck-val ((m <data_result>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_planner-msg:ck-val is deprecated.  Use robot_planner-msg:ck instead.")
  (ck m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <data_result>) ostream)
  "Serializes a message object of type '<data_result>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'cx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'cy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'cyaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ck))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <data_result>) istream)
  "Deserializes a message object of type '<data_result>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'cx) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'cy) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'cyaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ck) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<data_result>)))
  "Returns string type for a message object of type '<data_result>"
  "robot_planner/data_result")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'data_result)))
  "Returns string type for a message object of type 'data_result"
  "robot_planner/data_result")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<data_result>)))
  "Returns md5sum for a message object of type '<data_result>"
  "ac72c95b5c686c44d788b60e9209fa35")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'data_result)))
  "Returns md5sum for a message object of type 'data_result"
  "ac72c95b5c686c44d788b60e9209fa35")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<data_result>)))
  "Returns full string definition for message of type '<data_result>"
  (cl:format cl:nil "float32 cx~%float32 cy~%float32 cyaw~%float32 ck ~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'data_result)))
  "Returns full string definition for message of type 'data_result"
  (cl:format cl:nil "float32 cx~%float32 cy~%float32 cyaw~%float32 ck ~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <data_result>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <data_result>))
  "Converts a ROS message object to a list"
  (cl:list 'data_result
    (cl:cons ':cx (cx msg))
    (cl:cons ':cy (cy msg))
    (cl:cons ':cyaw (cyaw msg))
    (cl:cons ':ck (ck msg))
))
