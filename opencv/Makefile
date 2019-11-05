## -------------------------------------
## How to use
##  > make SRC=<.cpp File Name>
## -------------------------------------
SRC = ttxxx

CC     = clang++
##CCOPT  = -std=c++11 -I/usr/local/Cellar/opencv/3.4.1_2/include/opencv -I/usr/local/Cellar/opencv/3.4.1_2/include
CCOPT  = -std=c++11 $(shell pkg-config --cflags opencv4)
TARGET = a.out

#LINKOPT = -L/usr/local/Cellar/opencv/3.4.1_2/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dpm -lopencv_face -lopencv_photo -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopencv_core
LINKOPT = $(shell pkg-config --libs opencv4)

$(TARGET) : $(SRC)
	$(CC) $(CCOPT) $(LINKOPT) $(SRC) -o $@ 

clean :
	rm $(TARGET)

