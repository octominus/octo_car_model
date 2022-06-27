// Auto-generated. Do not edit!

// (in-package robot_planner.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class data_result {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.cx = null;
      this.cy = null;
      this.cyaw = null;
      this.ck = null;
    }
    else {
      if (initObj.hasOwnProperty('cx')) {
        this.cx = initObj.cx
      }
      else {
        this.cx = 0.0;
      }
      if (initObj.hasOwnProperty('cy')) {
        this.cy = initObj.cy
      }
      else {
        this.cy = 0.0;
      }
      if (initObj.hasOwnProperty('cyaw')) {
        this.cyaw = initObj.cyaw
      }
      else {
        this.cyaw = 0.0;
      }
      if (initObj.hasOwnProperty('ck')) {
        this.ck = initObj.ck
      }
      else {
        this.ck = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type data_result
    // Serialize message field [cx]
    bufferOffset = _serializer.float32(obj.cx, buffer, bufferOffset);
    // Serialize message field [cy]
    bufferOffset = _serializer.float32(obj.cy, buffer, bufferOffset);
    // Serialize message field [cyaw]
    bufferOffset = _serializer.float32(obj.cyaw, buffer, bufferOffset);
    // Serialize message field [ck]
    bufferOffset = _serializer.float32(obj.ck, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type data_result
    let len;
    let data = new data_result(null);
    // Deserialize message field [cx]
    data.cx = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [cy]
    data.cy = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [cyaw]
    data.cyaw = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [ck]
    data.ck = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robot_planner/data_result';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ac72c95b5c686c44d788b60e9209fa35';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 cx
    float32 cy
    float32 cyaw
    float32 ck 
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new data_result(null);
    if (msg.cx !== undefined) {
      resolved.cx = msg.cx;
    }
    else {
      resolved.cx = 0.0
    }

    if (msg.cy !== undefined) {
      resolved.cy = msg.cy;
    }
    else {
      resolved.cy = 0.0
    }

    if (msg.cyaw !== undefined) {
      resolved.cyaw = msg.cyaw;
    }
    else {
      resolved.cyaw = 0.0
    }

    if (msg.ck !== undefined) {
      resolved.ck = msg.ck;
    }
    else {
      resolved.ck = 0.0
    }

    return resolved;
    }
};

module.exports = data_result;
