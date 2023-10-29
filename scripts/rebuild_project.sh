#!/bin/bash -l

BUILD_DIR="build_debug"

# build project
cmake -B$BUILD_DIR > /dev/null && cmake --build $BUILD_DIR

if [ $? != 0 ]; then
    echo -e "Build failed"
    rm -rf $BUILD_DIR
    exit 2
fi

cd ${BUILD_DIR}
#make install

#cd ../
#rm -rf $BUILD_DIR
