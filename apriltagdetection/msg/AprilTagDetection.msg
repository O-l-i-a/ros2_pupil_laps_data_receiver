std_msgs/Header header           # Zeitstempel + frame_id
# Unique ID encoded in the tag
int32 id

# Tag family, e.g. "tagStandard41h12"
string family

# Physical size of the tag (edge length) in meters
float64 size

# Detection quality
# Number of bit errors corrected during decoding (0 = perfect)
float64 hamming

# Confidence score from the detector (higher is better)
float64 decision_margin

# Image-space information (pixel coordinates in the scene image)
# Center of the tag in pixels (u, v)
float64 center_x
float64 center_y

# Corners of the tag in pixels in image coordinates.
# Order: [x0, y0, x1, y1, x2, y2, x3, y3]
float64[8] corners

# 3D pose of the tag with respect to the scene camera frame
# Position in meters, orientation as quaternion
geometry_msgs/Pose pose

