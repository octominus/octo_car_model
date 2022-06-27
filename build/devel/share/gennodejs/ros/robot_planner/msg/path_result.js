// Auto-generated. Do not edit!

// (in-package robot_planner.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let data_result = require('./data_result.js');

//-----------------------------------------------------------

class path_result {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type path_result
    // Serialize message field [result]
    // Serialize the length for message field [result]
    bufferOffset = _serializer.uint32(obj.result.length, buffer, bufferOffset);
    obj.result.forEach((val) => {
      bufferOffset = data_result.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type path_result
    let len;
    let data = new path_result(null);
    // Deserialize message field [result]
    // Deserialize array length for message field [result]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.result = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.result[i] = data_result.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 16 * object.result.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robot_planner/path_result';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '05c8d58b6be9147bdddc88d0fd92da98';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    data_result[] result
    ================================================================================
    MSG: robot_planner/data_result
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
    const resolved = new path_result(null);
    if (msg.result !== undefined) {
      resolved.result = new Array(msg.result.length);
      for (let i = 0; i < resolved.result.length; ++i) {
        resolved.result[i] = data_result.Resolve(msg.result[i]);
      }
    }
    else {
      resolved.result = []
    }

    return resolved;
    }
};

module.exports = path_result;
