#!/bin/bash -l

BUILD_DIR="build_debug"

# build project
cmake -B$BUILD_DIR > /dev/null && cmake --build $BUILD_DIR

if [ $? != 0 ]; then
    echo -e "Build failed"
    rm -rf $BUILD_DIR
    exit 2
fi

<<<<<<< HEAD
cd ${BUILD_DIR}
#make install

#cd ../
#rm -rf $BUILD_DIR
||||||| parent of de9abf1 (update)
$BUILD_DIR/pointer_discussion_CPP
$BUILD_DIR/tests/*test


#rm -rf $BUILD_DIR
=======
cd ${BUILD_DIR}
make install

cd ../
rm -rf $BUILD_DIR
>>>>>>> de9abf1 (update)
