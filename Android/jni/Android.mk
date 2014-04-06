LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := mcserverwrapper

LOCAL_SRC_FILES := app-android.cpp ToJava.cpp

LOCAL_CFLAGS := -DANDROID_NDK \
				-O3 \
				-funroll-loops \
				-mfloat-abi=softfp -mfpu=neon \
				-fexceptions \


LOCAL_STATIC_LIBRARIES := cpufeatures

LOCAL_SHARED_LIBRARIES := MCServer

LOCAL_C_INCLUDES := ../src/ ../lib/


LOCAL_LDLIBS := -ldl -llog

include $(BUILD_SHARED_LIBRARY)
$(call import-module,cpufeatures)
