/** \file k4abttypes.h
 * Kinect For Azure Body Tracking SDK Type definitions.
 */

#ifndef K4ABTTYPES_H
#define K4ABTTYPES_H

#include <k4a/k4atypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup btcsdk C Reference
 *
 */
/**
 * \defgroup bthandles Handles
 * \ingroup btcsdk
 * Handles represent object instances.
 *
 * Handles are opaque pointers returned by the SDK which represent an object.
 *
 * @{
 */

/** Handle to k4a body tracking component.
 *
 * Handles are created with k4abt_tracker_create() and destroyed
 * with k4abt_tracker_destroy().
 * Invalid handles are set to 0.
 */
K4A_DECLARE_HANDLE(k4abt_tracker_t);

/** Handle to a k4a body tracking frame.
 *
 * Handles are created with k4abt_tracker_pop_result and closed
 * with k4abt_frame_release. Invalid handles are set to 0.
 */
K4A_DECLARE_HANDLE(k4abt_frame_t);

/**
 *
 * @}
 *
 * \defgroup btenums Enumerations
 * \ingroup btcsdk
 *
 * Enumeration types used by APIs.
 *
 * @{
 */

/** Model fitting joint definition
 */
typedef enum
{
    K4ABT_JOINT_PELVIS = 0,
    K4ABT_JOINT_SPINE_NAVAL,
    K4ABT_JOINT_SPINE_CHEST,
    K4ABT_JOINT_NECK,
    K4ABT_JOINT_CLAVICLE_LEFT,
    K4ABT_JOINT_SHOULDER_LEFT,
    K4ABT_JOINT_ELBOW_LEFT,
    K4ABT_JOINT_WRIST_LEFT,
    K4ABT_JOINT_CLAVICLE_RIGHT,
    K4ABT_JOINT_SHOULDER_RIGHT,
    K4ABT_JOINT_ELBOW_RIGHT,
    K4ABT_JOINT_WRIST_RIGHT,
    K4ABT_JOINT_HIP_LEFT,
    K4ABT_JOINT_KNEE_LEFT,
    K4ABT_JOINT_ANKLE_LEFT,
    K4ABT_JOINT_FOOT_LEFT,
    K4ABT_JOINT_HIP_RIGHT,
    K4ABT_JOINT_KNEE_RIGHT,
    K4ABT_JOINT_ANKLE_RIGHT,
    K4ABT_JOINT_FOOT_RIGHT,
    K4ABT_JOINT_HEAD,
    K4ABT_JOINT_NOSE,
    K4ABT_JOINT_EYE_LEFT,
    K4ABT_JOINT_EAR_LEFT,
    K4ABT_JOINT_EYE_RIGHT,
    K4ABT_JOINT_EAR_RIGHT,
    K4ABT_JOINT_COUNT
} k4abt_joint_id_t;

/** Sensor mounting orientation types.
 *
 * \remarks
 * This enumeration specifies the sensor mounting orientation. Passing the correct orientation in k4abt_tracker_create()
 * can help the body tracker to achieve more accurate body tracking.
 *
 * \remarks
 * The sensor orientation is defined while facing the camera.
 */
typedef enum
{
    K4ABT_SENSOR_ORIENTATION_DEFAULT = 0,        /**< Mount the sensor at its default orientation */
    K4ABT_SENSOR_ORIENTATION_CLOCKWISE90,        /**< Clockwisely rotate the sensor 90 degree */
    K4ABT_SENSOR_ORIENTATION_COUNTERCLOCKWISE90, /**< Counter-clockwisely rotate the sensor 90 degrees */
    K4ABT_SENSOR_ORIENTATION_FLIP180,            /**< Mount the sensor upside-down */
} k4abt_sensor_orientation_t;

/** Configuration parameters for a k4abt body tracker
 *
 * \remarks
 * Used by k4abt_tracker_create() to specify the configuration of the k4abt tracker
 */
typedef struct _k4abt_tracker_configuration_t
{
    /** The sensor mounting orientation type.
     *
     * Setting the correct orientation can help the body tracker to achieve more accurate body tracking results
     */
    k4abt_sensor_orientation_t sensor_orientation;
} k4abt_tracker_configuration_t;

/**
 *
 * @}
 *
 * \defgroup btstructures Structures
 * \ingroup btcsdk
 *
 * Structures used in the API.
 *
 * @{
 */

/** k4a_quaternion_t
 */
typedef union
{
    /** WXYZ or array representation of quaternion */
    struct _wxyz
    {
        float w; /**< W representation of a quaternion */
        float x; /**< X representation of a quaternion */
        float y; /**< Y representation of a quaternion */
        float z; /**< Z representation of a quaternion */
    } wxyz;      /**< W, X, Y, Z representation of a quaternion */
    float v[4];  /**< Array representation of a quaternion */
} k4a_quaternion_t;

/** Structure to define a single joint
 *
 * The position and orientation together defines the coordinate system for the given joint. They are defined relative
 * to the sensor global coordinate system.
 */
typedef struct _k4abt_joint_t
{
    k4a_float3_t     position;    /**< The position of the joint specified in millimeters*/
    k4a_quaternion_t orientation; /**< The orientation of the joint specified in normalized quaternion*/
} k4abt_joint_t;

/** Structure to define joints for skeleton
 */
typedef struct _k4abt_skeleton_t
{
    k4abt_joint_t joints[K4ABT_JOINT_COUNT]; /**< The joints for the body*/
} k4abt_skeleton_t;

/** Structure to define body
 */
typedef struct _k4abt_body_t
{
    uint32_t id;                /**< An id for the body that can be used for frame-to-frame correlation*/
    k4abt_skeleton_t skeleton;  /**< The skeleton information for the body */
} k4abt_body_t;

/**
 *
 * @}
 *
 * \defgroup btdefinitions Definitions
 * \ingroup btcsdk
 *
 * Definition of constant values.
 *
 * @{
 */

/** The pixel value that indicates the pixel belong to the background in the body id map
 */
#define K4ABT_BODY_INDEX_MAP_BACKGROUND 255

/** The invalid body id value
 */
#define K4ABT_INVALID_BODY_ID 0xFFFFFFFF

 /** The default tracker temporal smoothing factor
  */
#define K4ABT_DEFAULT_TRACKER_SMOOTHING_FACTOR 0.5f

/** Default configuration setting for k4abt tracker.
 *
 * \remarks
 * Use this setting to initialize a \ref k4abt_tracker_configuration_t to a default state.
 */
static const k4abt_tracker_configuration_t K4ABT_TRACKER_CONFIG_DEFAULT = { K4ABT_SENSOR_ORIENTATION_DEFAULT };

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* K4ABTTYPES_H */