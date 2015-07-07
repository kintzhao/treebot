#include "detectqrcode.h"
DetctQrcode::DetctQrcode(char *mapFile)
{
	useBCH = false;
	// display = cv::Mat::zeros(640,480,CV_32F);
	if (mapFile != NULL)
	{
		printf("%s <configuration filename>", mapFile);
	}
	createMap(input_data_, mapFile);
	//迭代操作  初始化vextor[0-599]:  ht orients xoff yoff sideSizes
	for (int hti = 0; hti < 40; hti++)
	{
		//配置参数字符等价
		std::string htstr = arrToStr("ht", hti);
		std::string orientsstr = arrToStr("orients", hti);
		std::string xoffstr = arrToStr("xoff", hti);
		std::string yoffstr = arrToStr("yoff", hti);
		std::string sideSizesstr = arrToStr("sideSizes", hti);

		std::string corn0x = arrToStr("corn0x", hti);
		std::string corn0y = arrToStr("corn0y", hti);
		std::string corn0z = arrToStr("corn0z", hti);

		std::string corn1x = arrToStr("corn1x", hti);
		std::string corn1y = arrToStr("corn1y", hti);
		std::string corn1z = arrToStr("corn1z", hti);

		std::string corn2x = arrToStr("corn2x", hti);
		std::string corn2y = arrToStr("corn2y", hti);
		std::string corn2z = arrToStr("corn2z", hti);

		std::string corn3x = arrToStr("corn3x", hti);
		std::string corn3y = arrToStr("corn3y", hti);
		std::string corn3z = arrToStr("corn3z", hti);

		std::string centerx = arrToStr("centerx", hti);
		std::string centery = arrToStr("centery", hti);
		std::string centerz = arrToStr("centerz", hti);


		MapType::iterator it;
		it = input_data_.find(htstr.c_str());
		if (it != input_data_.end())
			ht_.push_back(atof(it->second.c_str())); // Add data to the end of the %vector.
		else
			ht_.push_back(0.0);

		it = input_data_.find(orientsstr.c_str());
		if (it != input_data_.end())
			orients_.push_back(atoi(it->second.c_str()));
		else
			orients_.push_back(0.0);

		it = input_data_.find(xoffstr.c_str());
		if (it != input_data_.end())
			x_off_.push_back(atoi(it->second.c_str()));
		else
			x_off_.push_back(0.0);

		it = input_data_.find(yoffstr.c_str());
		if (it != input_data_.end())
			y_off_.push_back(atoi(it->second.c_str()));
		else
			y_off_.push_back(0.0);

		it = input_data_.find(sideSizesstr.c_str());
		if (it != input_data_.end())
			side_sizes_.push_back(atoi(it->second.c_str()));
		else
			side_sizes_.push_back(0.0);
		//__________________________________________________________________
		CPointsFourWorld corns_four;
		it = input_data_.find(corn0x.c_str());
		if (it != input_data_.end())
			corns_four.corn0.X = atof(it->second.c_str());
		else
			corns_four.corn0.X = 0.0;
		it = input_data_.find(corn0y.c_str());
		if (it != input_data_.end())
			corns_four.corn0.Y = atof(it->second.c_str());
		else
			corns_four.corn0.Y = 0.0;
		it = input_data_.find(corn0z.c_str());
		if (it != input_data_.end())
			corns_four.corn0.Z = atof(it->second.c_str());
		else
			corns_four.corn0.Z = 0.0;


		it = input_data_.find(corn1x.c_str());
		if (it != input_data_.end())
			corns_four.corn1.X = atof(it->second.c_str());
		else
			corns_four.corn1.X = 0.0;
		it = input_data_.find(corn1y.c_str());
		if (it != input_data_.end())
			corns_four.corn1.Y = atof(it->second.c_str());
		else
			corns_four.corn1.Y = 0.0;
		it = input_data_.find(corn1z.c_str());
		if (it != input_data_.end())
			corns_four.corn1.Z = atof(it->second.c_str());
		else
			corns_four.corn1.Z = 0.0;

		it = input_data_.find(corn2x.c_str());
		if (it != input_data_.end())
			corns_four.corn2.X = atof(it->second.c_str());
		else
			corns_four.corn2.X = 0.0;
		it = input_data_.find(corn2y.c_str());
		if (it != input_data_.end())
			corns_four.corn2.Y = atof(it->second.c_str());
		else
			corns_four.corn2.Y = 0.0;
		it = input_data_.find(corn2z.c_str());
		if (it != input_data_.end())
			corns_four.corn2.Z = atof(it->second.c_str());
		else
			corns_four.corn2.Z = 0.0;


		it = input_data_.find(corn3x.c_str());
		if (it != input_data_.end())
			corns_four.corn3.X = atof(it->second.c_str());
		else
			corns_four.corn3.X = 0.0;
		it = input_data_.find(corn3y.c_str());
		if (it != input_data_.end())
			corns_four.corn3.Y = atof(it->second.c_str());
		else
			corns_four.corn3.Y = 0.0;
		it = input_data_.find(corn3z.c_str());
		if (it != input_data_.end())
			corns_four.corn3.Z = atof(it->second.c_str());
		else
			corns_four.corn3.Z = 0.0;


		it = input_data_.find(centerx.c_str());
		if (it != input_data_.end())
			corns_four.center.X = atof(it->second.c_str());
		else
			corns_four.center.X = 0.0;
		it = input_data_.find(centery.c_str());
		if (it != input_data_.end())
			corns_four.center.Y = atof(it->second.c_str());
		else
			corns_four.center.Y = 0.0;
		it = input_data_.find(centerz.c_str());
		if (it != input_data_.end())
			corns_four.center.Z = atof(it->second.c_str());
		else
			corns_four.center.Z = 0.0;
		corns_four.ID = hti;
		corners_world_.push_back(corns_four);
	}
	//输出   vextor[0-599]:  ht orients xoff yoff sideSizes
	for (int hti = 0; hti < 40; hti++)
	{
		if (ht_[hti] != 0)
		{
			cout << " Mark Id: " << hti << "have been marked.\n" << endl;
			cout << " ht[" << hti << "]=" << ht_[hti] << endl;
			cout << " orients[" << hti << "]=" << orients_[hti] << endl;
			cout << " xoff[" << hti << "]=" << x_off_[hti] << endl;
			cout << " yoff[" << hti << "]=" << y_off_[hti] << endl;
			cout << " sideSizes[" << hti << "]=" << side_sizes_[hti] << endl;
		}
	}

	cv::FileStorage fs2(input_data_[std::string("cvCalibFile")].c_str(), cv::FileStorage::READ);
	camera_matrix_ = cv::Mat::eye(3, 3, CV_64F);
	distcoeffs_ = cv::Mat::zeros(5, 1, CV_64F);
	//获取标定参数
	fs2["Camera_Matrix"] >> camera_matrix_;               //相机矩阵
	fs2["Distortion_Coefficients"] >> distcoeffs_;        //畸变系数
	//相机焦距相关
	cout << "camera_matrix_" << camera_matrix_ << endl;
	cout << "distcoeffs_" << distcoeffs_ << endl;
	camInnerPara.fx = camera_matrix_.at<double>(0, 0) / 100.0; camInnerPara.fy = camera_matrix_.at<double>(1, 1) / 100.0;
	camInnerPara.dx = camera_matrix_.at<double>(0, 2) / 100.0; camInnerPara.dy = camera_matrix_.at<double>(1, 2) / 100.0;

	p_tracker_marks_ = new TrackerSingleMarker(ar_mode_width, ar_mode_height, 5, 6, 6, 6, 0);
}
DetctQrcode::~DetctQrcode()
{
    delete  p_tracker_marks_ ;
}
vector<CPointsFour>  DetctQrcode::detectLandmarks(cv::Mat image, int& MarkNum)
{
	loopClear();
	gray = image.clone();
	cv::cvtColor(image, gray, CV_BGR2GRAY);
	show_landmark_img_ = image.clone();
	cv::rectangle(show_landmark_img_, cvPoint(319, 239), cvPoint(321, 241), CV_RGB(0, 255, 0), 1, 8); //圈取图像中心点
	//    TrackerSingleMarker* ptrackerWhole = new TrackerSingleMarker(ar_mode_width, ar_mode_height, 5, 6, 6, 6, 0);
	trackerFunction(p_tracker_marks_);//ARToolkitplus 处理二维码信息  1000次自动track
	int tryCount = 0;
    //namedWindow("edges2", 1);
    //imshow("edges2", gray);
	cv::waitKey(10);

	while (tryCount < 253)
	{
		if (input_data_[std::string("processingType")] == std::string("1") || input_data_[std::string("processingType")] == std::string("3"))
		{
			p_tracker_marks_->setThreshold(tryCount + 1);
		}

		else
		{
			tryCount = 300;
		}
		//Returns:detected markers in image
		std::vector<int> markerId = p_tracker_marks_->calc(gray.data, &nMarker_info, &nNumMarkers);
		cout << "nNumMarkers" << nNumMarkers << "  " << markerId.size() << endl;
		//        MarkNum = markerId.size();
		tryCount++;
		for (int i = 0; i < nNumMarkers; i++)
		{
			if (nMarker_info[i].id != -1)
			{
				if (ht_[nMarker_info[i].id] >0.05)
				{
					int value_thre = p_tracker_marks_->getThreshold();
					cout << " threshold value:  " << value_thre << endl;
					//目标标记点 nMarker_info[i]   foundCode
					found_code = true;
					Mark = nMarker_info[i];
					double robot_theta = calcPan(nMarker_info[i], orients_);
					bool id_was_detected = false;
					for (int ii = 0; ii < detectedID.size(); ii++)
					{
						if (detectedID[ii] == nMarker_info[i].id)
						{
							robot_theta = calcPan(nMarker_info[i], orients_);
							ID_Theta[ii].push_back(robot_theta);//???摄像头的旋转 也就是robot(theta)

							id_was_detected = true;
							ID_X[ii].push_back(nMarker_info[i].pos[0]);//存mark_ii在不同阈值下ID_X整体再循环一次
							ID_Y[ii].push_back(nMarker_info[i].pos[1]);
							double side_calc = sideCalc(nMarker_info[i]);
							side_size[ii].push_back(side_calc);

							ConerPoint  center, corner0, corner1, corner2, corner3;
							center.init(nMarker_info[i].pos[0], nMarker_info[i].pos[1]);
							corner0.init(nMarker_info[i].vertex[(4 - Mark.dir + 0) % 4][0], nMarker_info[i].vertex[(4 - Mark.dir + 0) % 4][1]);
							corner1.init(nMarker_info[i].vertex[(4 - Mark.dir + 1) % 4][0], nMarker_info[i].vertex[(4 - Mark.dir + 1) % 4][1]);
							corner2.init(nMarker_info[i].vertex[(4 - Mark.dir + 2) % 4][0], nMarker_info[i].vertex[(4 - Mark.dir + 2) % 4][1]);
							corner3.init(nMarker_info[i].vertex[(4 - Mark.dir + 3) % 4][0], nMarker_info[i].vertex[(4 - Mark.dir + 3) % 4][1]);

							CPointsFour points_temp;
							points_temp.ID = nMarker_info[i].id;
							points_temp.init(corner0, corner1, corner2, corner3, center);
							coners[ii].push_back(points_temp);
						}
					}
					if (!id_was_detected)   //主要是为了多阈值处理下（在循环 while(tryCount < 253)下只进来一次）先填充满ID_X容器，确定好detectedID的数量。
					{                       // X_arr的填充顺序是nMarker_info[i]中i的顺序。。
						detectedID.push_back(nMarker_info[i].id);
						vector<double> Theta_arr;
						Theta_arr.push_back(robot_theta);
						ID_Theta.push_back(Theta_arr);

						vector<double> X_arr;
						X_arr.push_back(nMarker_info[i].pos[0]);
						ID_X.push_back(X_arr);
						vector<double> Y_arr;
						Y_arr.push_back(nMarker_info[i].pos[1]);
						ID_Y.push_back(Y_arr);
						vector<double> side_size_arr;
						double side_arr = sideCalc(nMarker_info[i]);
						side_size_arr.push_back(side_arr);
						side_size.push_back(side_size_arr);
						MarkerPrototypes.push_back(nMarker_info[i]);

						ConerPoint  center, corner0, corner1, corner2, corner3;
						center.init(nMarker_info[i].pos[0], nMarker_info[i].pos[1]);
						corner0.init(nMarker_info[i].vertex[(4 - Mark.dir + 0) % 4][0], nMarker_info[i].vertex[(4 - Mark.dir + 0) % 4][1]);
						corner1.init(nMarker_info[i].vertex[(4 - Mark.dir + 1) % 4][0], nMarker_info[i].vertex[(4 - Mark.dir + 1) % 4][1]);
						corner2.init(nMarker_info[i].vertex[(4 - Mark.dir + 2) % 4][0], nMarker_info[i].vertex[(4 - Mark.dir + 2) % 4][1]);
						corner3.init(nMarker_info[i].vertex[(4 - Mark.dir + 3) % 4][0], nMarker_info[i].vertex[(4 - Mark.dir + 3) % 4][1]);

						CPointsFour points_temp;
						points_temp.init(corner0, corner1, corner2, corner3, center);
						points_temp.ID = nMarker_info[i].id;
						vector<CPointsFour> coners_temp;
						coners_temp.push_back(points_temp);
						coners.push_back(coners_temp);
					}
				}
			}
		}
	}
	MarkNum = coners.size();

	//average
	for (int i = 0; i < MarkNum; ++i)
	{
		CPointsFour  c_temp;

		c_temp = averageCPointsFour(coners[i], 10.0, 0.0, 2.0, 6420);
		//c_temp.ID = MarkerPrototypes[i].id ;
		coners_aver.push_back(c_temp);
	}
	drawCoordinate(show_landmark_img_);
	drawQrcode();    //draw the square-qrcode_fourSide
	return coners_aver;  //返回的值是实际距离值
}
void DetctQrcode::getQrPos(void)
{
	points2d_.clear();
	points3d_.clear();
	for (int i = 0; i<coners_aver.size(); ++i)
	{
		int id = coners_aver[i].ID;
		points2d_.push_back(Point2f(coners_aver[i].corn0.X, coners_aver[i].corn0.Y));
		points2d_.push_back(Point2f(coners_aver[i].corn1.X, coners_aver[i].corn1.Y));
		points2d_.push_back(Point2f(coners_aver[i].corn2.X, coners_aver[i].corn2.Y));
		points2d_.push_back(Point2f(coners_aver[i].corn3.X, coners_aver[i].corn3.Y));

		points3d_.push_back(Point3f(corners_world_[id].corn0.X, corners_world_[id].corn0.Y, corners_world_[id].corn0.Z));
		points3d_.push_back(Point3f(corners_world_[id].corn1.X, corners_world_[id].corn1.Y, corners_world_[id].corn1.Z));
		points3d_.push_back(Point3f(corners_world_[id].corn2.X, corners_world_[id].corn2.Y, corners_world_[id].corn2.Z));
		points3d_.push_back(Point3f(corners_world_[id].corn3.X, corners_world_[id].corn3.Y, corners_world_[id].corn3.Z));
	}
}
void DetctQrcode::drawQrcode(void)   //draw the square-qrcode_fourSide
{
	for (int count = 0; count < nNumMarkers; count++)
	{
		Mark = nMarker_info[count];
		if (Mark.id != -1 && ht_[Mark.id] > 0.01)
		{
			cv::line(show_landmark_img_, cv::Point(Mark.vertex[0][0], Mark.vertex[0][1]), cv::Point(Mark.vertex[1][0], Mark.vertex[1][1]), CV_RGB(255, 0, 0), 1, 8);
			cv::line(show_landmark_img_, cv::Point(Mark.vertex[1][0], Mark.vertex[1][1]), cv::Point(Mark.vertex[2][0], Mark.vertex[2][1]), CV_RGB(255, 0, 0), 1, 8);
			cv::line(show_landmark_img_, cv::Point(Mark.vertex[2][0], Mark.vertex[2][1]), cv::Point(Mark.vertex[3][0], Mark.vertex[3][1]), CV_RGB(255, 0, 0), 1, 8);
			cv::line(show_landmark_img_, cv::Point(Mark.vertex[3][0], Mark.vertex[3][1]), cv::Point(Mark.vertex[0][0], Mark.vertex[0][1]), CV_RGB(255, 0, 0), 1, 8);

            string dir_str = int2str(Mark.dir);
            string tx0 = int2str((4 - Mark.dir + 0) % 4);
            string tx1 = int2str((4 - Mark.dir + 1) % 4);
            string tx2 = int2str((4 - Mark.dir + 2) % 4);
            string tx3 = int2str((4 - Mark.dir + 3) % 4);


			cv::putText(show_landmark_img_, dir_str, cv::Point(400, 400), CV_FONT_HERSHEY_COMPLEX, 2, CV_RGB(0, 0, 255));
			cv::putText(show_landmark_img_, tx0, cv::Point(Mark.vertex[(4 - Mark.dir + 0) % 4][0], Mark.vertex[(4 - Mark.dir + 0) % 4][1]), CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(0, 0, 0));
			cv::putText(show_landmark_img_, tx1, cv::Point(Mark.vertex[(4 - Mark.dir + 1) % 4][0], Mark.vertex[(4 - Mark.dir + 1) % 4][1]), CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(0, 0, 0));
			cv::putText(show_landmark_img_, tx2, cv::Point(Mark.vertex[(4 - Mark.dir + 2) % 4][0], Mark.vertex[(4 - Mark.dir + 2) % 4][1]), CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(0, 0, 0));
			cv::putText(show_landmark_img_, tx3, cv::Point(Mark.vertex[(4 - Mark.dir + 3) % 4][0], Mark.vertex[(4 - Mark.dir + 3) % 4][1]), CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(0, 0, 0));
		}
		std::string text = "ID_" + int2str(Mark.id);
		cv::putText(show_landmark_img_, text, cvPoint(Mark.pos[0], Mark.pos[1]), CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(255, 0, 0));
		count++;
	}
}
void DetctQrcode::drawCoordinate(cv::Mat& mat)
{
	std::string text = "X";
	cv::putText(mat, text, cvPoint(20, mat.rows - 20), CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(0, 0, 255));
	cv::line(mat, cv::Point(1, 1), cv::Point(1, mat.rows), CV_RGB(255, 0, 0), 1, 8);

	text = "O";
	cv::putText(mat, text, cvPoint(20, 20), CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(0, 0, 255));

	text = "Y";
	cv::putText(mat, text, cvPoint(mat.cols - 20, 20), CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(0, 0, 255));
	cv::line(mat, cv::Point(1, 1), cv::Point(mat.cols, 1), CV_RGB(255, 0, 0), 1, 8);

    //center
    cv::rectangle(mat,cv::Point(mat.cols/2-1,mat.rows/2-1),cv::Point(mat.cols/2+1,mat.rows/2+1),CV_RGB(255,255,0),1,8);

    //轴线
    cv::line(mat, cv::Point(mat.cols/2,0), cv::Point(mat.cols/2, mat.rows), CV_RGB(255, 0, 0), 1, 8);
    cv::line(mat, cv::Point(0, mat.rows/2), cv::Point(mat.cols, mat.rows/2), CV_RGB(255, 0, 0), 1, 8);

}
std::string  DetctQrcode::int2str(int num)
{
	std::stringstream ss;
	ss << num;
	std::string text = ss.str();
	return text;

}
void DetctQrcode::createMap(MapType &inputData,  char * filename)
{

	std::string line;
	std::string startBraceEnd(">");
	std::string endBraceStart("</");
	std::ifstream infile(filename);

	while (std::getline(infile, line))
	{
		bool readFine = false;
		if (line.size() > 0 && line[0] == '<' && line[line.size() - 1] == '>')
		{
			std::size_t pSBE = line.find(startBraceEnd);
			std::size_t pEBS = line.find(endBraceStart);
			if (pSBE != std::string::npos && pEBS != std::string::npos && pSBE < pEBS)
			{
				std::string marker1 = line.substr(1, pSBE - 1);
				std::string marker2 = line.substr(pEBS + 2, line.size() - pEBS - 3);
				if (marker1 == marker2)
				{
					std::string content = line.substr(pSBE + 1, pEBS - pSBE - 1);
					inputData.insert(pair<string, string>(marker1, content));
					readFine = true;
				}
			}
		}
		if (readFine == true)
		{
			cout << line << " READ FINE " << endl;
		}
		else
		{
			cout << line << " ERROR ERROR ERROR !!!!!!!!!!!!! " << endl;
		}
	}

}
void DetctQrcode::undistortImage(IplImage* frame, cv::Mat & map1, cv::Mat & map2)
{
	cout << "frame: " << frame->width << " x " << frame->height << endl;
	cout << "frame: " << map1.size() << endl;
	cout << "frame: " << map2.size() << endl;
	cv::Mat viewDistorted(frame, false);
	cv::Mat viewRectified;
	// warps the image using the precomputed maps.
	cv::remap(viewDistorted, viewRectified, map1, map2, cv::INTER_LINEAR);
	cv::Mat FM(frame);
	viewRectified.copyTo(FM);
}
std::string DetctQrcode::arrToStr(const char * c, int i)
{
	std::stringstream ss;
	ss << c << i;

	std::string res;
	ss >> res;

	return res;
}
void   DetctQrcode::gradientNormalizePic(cv::Mat &cutout)
{
	double rowsDiff = 0;
	for (int x = 0; x < cutout.cols; x++)
	{
		int diffCounter = 0;
		int diffAcc = 0;
		for (int y = 1; y < cutout.rows; y++)
		{
			int diff = cutout.at<uchar>(y, x) - cutout.at<uchar>(y - 1, x);
			if (abs(diff) < 5)
			{
				diffAcc += diff;
				diffCounter++;
			}
		}
		rowsDiff += (double)diffAcc / (double)diffCounter;
	}

	rowsDiff = (double)rowsDiff / (double)cutout.cols;


	double colsDiff = 0;
	for (int y = 0; y < cutout.rows; y++)
	{
		int diffCounter = 0;
		int diffAcc = 0;
		for (int x = 1; x < cutout.cols; x++)
		{
			int diff = cutout.at<uchar>(y, x) - cutout.at<uchar>(y, x - 1);
			if (abs(diff) < 5)
			{
				diffAcc += diff;
				diffCounter++;
			}
		}
		colsDiff += (double)diffAcc / (double)diffCounter;
	}
	colsDiff = (double)colsDiff / (double)cutout.rows;
	// 均值行列差分作为起始项
	double startdr = rowsDiff * cutout.rows / 2.0;
	double startdc = colsDiff * cutout.cols / 2.0;

	for (int x = 0; x < cutout.cols; x++)
	{
		double adjr = startdr;
		for (int y = 0; y < cutout.rows; y++)
		{
			int newVal = ((double)cutout.at<uchar>(y, x)) + adjr;
			newVal = newVal >= 0 ? newVal : 0;
			newVal = newVal < 256 ? newVal : 255;
			cutout.at<uchar>(y, x) = newVal;
			adjr -= rowsDiff;
		}
	}

	for (int y = 0; y < cutout.rows; y++)
	{
		double adjc = startdc;
		for (int x = 1; x < cutout.cols; x++)
		{
			int newVal = ((double)cutout.at<uchar>(y, x)) + adjc;
			newVal = newVal >= 0 ? newVal : 0;
			newVal = newVal < 256 ? newVal : 255;
			cutout.at<uchar>(y, x) = newVal;
			adjc -= colsDiff;

		}
	}
}
int    DetctQrcode::flipv(int y)
{
	return (y - 240) * -1.0 + 240;
}
int    DetctQrcode::fliph(int x)
{
	return (x - 320) * -1.0 + 320;
}
double DetctQrcode::getPan(double a1, double b1, double a2, double b2, int dirNum, int side)
{
	double pan = atan(-1.0 * a1 / b1) + 1.57079632679;


	if (dirNum == 0 || dirNum == 1)
		pan = pan + 3.141592653589793;

	if ((pan > 2.7 || pan < .4) && (dirNum == 0 || dirNum == 3))
	{
		pan = atan(-1.0 * a2 / b2);
	}

	if ((pan > 2.7 || pan < .4) && (dirNum == 1 || dirNum == 2))
	{
		pan = atan(-1.0 * a2 / b2) + 3.141592653589793;
	}

	if (dirNum == 0 && pan < 1.58 && pan > .3)
	{
		pan = -1.0 * pan;
	}

	return pan;

}
double DetctQrcode::combinePan(double pan, double pan2)
{
	if (fabs(pan - pan2) > 5)
	{
		if (pan > pan2)
		{
			pan2 = pan2 + 3.141592653589793 * 2.0;
		}
		else
		{
			pan = pan + 3.141592653589793 * 2.0;
		}
	}

	return (pan + pan2) / 2.0;
}
double DetctQrcode::normalizePan(double pan)
{
	if (pan < -3.141592653589793)
		pan = pan + 3.141592653589793 * 2.0;

	if (pan > 3.141592653589793)
		pan = pan - 3.141592653589793 * 2.0;

	return pan;
}
double DetctQrcode::calcPan(ARMarkerInfo arcode /*nMarker_info*/, vector<int> orients)
{
	/*   for(int i=0;i<4;i++)
	{
	cout<<"------mark:"<<arcode.id<<"  arcode[line]a b:"<<arcode.line[i][0]<<"  "<<arcode.line[i][1]<< endl;
	cout<<"arcode.vertex x y:"<<arcode.vertex[i][0]<<"  "<<arcode.vertex[i][1]<< endl;
	cout<< endl;
	}
	cout<<"arcode"<<arcode.id<<"-----dir: =" <<arcode.dir<< endl;
	*/
	double pan1A = atan(arcode.line[0][1] / arcode.line[0][0]);
	double pan3A = atan(arcode.line[2][1] / arcode.line[2][0]);
	double pan2A = atan(-1.0 * arcode.line[1][0] / arcode.line[1][1]);
	double pan4A = atan(-1.0 * arcode.line[3][0] / arcode.line[3][1]);

	double pan1B = atan(-1.0 * arcode.line[0][0] / arcode.line[0][1]);
	double pan3B = atan(-1.0 * arcode.line[2][0] / arcode.line[2][1]);
	double pan2B = atan(arcode.line[1][1] / arcode.line[1][0]);
	double pan4B = atan(arcode.line[3][1] / arcode.line[3][0]);

	//    cout<<"pan1A(b/a) "<<pan1A*57.3<<"---pan1B-(-a/b)-: =" <<pan1B*57.3<< endl;
	double absPanA = 0;
	double absPanB = 0;
	double panA = 0;
	double panB = 0;

	if (arcode.dir % 2 == 0)
	{
		absPanA = fabs(pan1A) + fabs(pan3A);
		absPanB = fabs(pan1B) + fabs(pan3B);
		panA = pan1A + pan3A;
		panB = pan1B + pan3B;
	}
	else
	{
		absPanA = fabs(pan2A) + fabs(pan4A);
		absPanB = fabs(pan2B) + fabs(pan4B);
		panA = pan2A + pan4A;
		panB = pan2B + pan4B;
	}

	panA /= -2.0;
	panB /= -2.0;
	panB += 3.14159265358979323846 / 2.0;
	double pan = (absPanA > absPanB ? panB : panA);

	pan += (arcode.dir - 3)*  3.14159265358979323846 / 2.0;
	pan = normalizePan(pan);
	pan = pan * -1.0;

	pan += orients[arcode.id] * 3.14159265358979323846 / 2.0 - 3.14159265358979323846;

	while (pan >  3.14159265358979323846 * 3.0 / 2.0)
		pan = pan - 3.14159265358979323846 * 2.0;

	while (pan < -1.0 *  3.14159265358979323846 / 2.0)
		pan = pan + 3.14159265358979323846 * 2.0;
	return pan;

}
/*与标记的旋转方向有关    标记边的方向号
Direction that tells about the rotation about the marker (possible values are 0, 1, 2 or 3).
This parameter makes it possible to tell about the line order of the detected marker
(so which line is the first one) and so find the first vertex.
*/
void   DetctQrcode::normalizeOrientation(ARMarkerInfo nMarker_info, vector<int> orients, int &dirNum, int &v1, int &v2, int &side)
{
	dirNum = (nMarker_info.dir - orients[nMarker_info.id] + 3) % 4;

	v1 = 0;
	v2 = 1;
	side = 0;

	if (dirNum == 0)
	{
		v1 = 0;
		v2 = 1;
		side = 2;
	}
	else if (dirNum == 1)
	{
		v1 = 3;
		v2 = 0;
		side = 1;
	}
	else if (dirNum == 2)
	{
		v1 = 2;
		v2 = 3;
		side = 0;
	}
	else
	{
		v1 = 1;
		v2 = 2;
		side = 3;
	}
}

/* 找到最大的值与相应的指数。//均值换算  加了滤波。最大值滤波。范围判断。累加求和
double QRCodeLocalizer::avgMode(vector<double> data, double multiplier, double shift, double range ,int bucketAmount)
{

int buckets[bucketAmount];
for(int i = 0;i< bucketAmount;i++)
buckets[i]=0;

for(int i = 0 ; i < data.size();i++)
{
int index = data[i]*multiplier+shift;
buckets[index] = buckets[index]+1;
}

int maxBucket = -1;
int maxBucketIndex = 0;
for(int i = 0;i< bucketAmount;i++)
{
if( maxBucket < buckets[i] )
{
maxBucket = buckets[i];
maxBucketIndex = i;
}
}

int count = 0;
double accum = 0.0;
for(int i = 0 ; i < data.size();i++)
{
if ( fabs ( ( (double) maxBucketIndex ) - ( data[i] * multiplier + shift ) ) < range )
{
count++;
accum = accum + data[i];
}
}

return  accum / ( (double) count );
}
*/

double DetctQrcode::averageVector(vector<double> data, double multiplier, double shift, double range, int bucketAmount)
{
	int count = 0;
	double accum = 0.0;
	for (int i = 0; i < data.size(); i++)
	{
		count++;
		accum = accum + data[i];
	}
	return  accum / count;
}
CPointsFour DetctQrcode::averageCPointsFour(vector<CPointsFour> data, double multiplier, double shift, double range, int bucketAmount)
{
	int count = 0;
	int qr_id = 0;
	ConerPoint  center, corner0, corner1, corner2, corner3;
	center.init(0, 0); corner0.init(0, 0); corner1.init(0, 0); corner2.init(0, 0); corner3.init(0, 0);
	for (int i = 0; i < data.size(); i++)
	{
		count++;
		qr_id += data[i].ID;
		center.X += data[i].center.X;
		center.Y += data[i].center.Y;
		corner0.X += data[i].corn0.X;
		corner0.Y += data[i].corn0.Y;
		corner1.X += data[i].corn1.X;
		corner1.Y += data[i].corn1.Y;
		corner2.X += data[i].corn2.X;
		corner2.Y += data[i].corn2.Y;
		corner3.X += data[i].corn3.X;
		corner3.Y += data[i].corn3.Y;
	}
	qr_id = qr_id / count;
	center.X = center.X / count;
	center.Y = center.Y / count;
	corner0.X = corner0.X / count;
	corner0.Y = corner0.Y / count;
	corner1.X = corner1.X / count;
	corner1.Y = corner1.Y / count;
	corner2.X = corner2.X / count;
	corner2.Y = corner2.Y / count;
	corner3.X = corner3.X / count;
	corner3.Y = corner3.Y / count;
	CPointsFour points_temp;
	points_temp.init(corner0, corner1, corner2, corner3, center);
	points_temp.ID = qr_id;
	return points_temp;

}
/*边长计算  矩形四个顶点  */
double DetctQrcode::sideCalc(ARMarkerInfo Mark)
{
	double ddAcc = 0.0;
	double xd, yd, dd;
	for (int i = 0; i < 4; i++)
	{
		xd = Mark.vertex[i][0] - Mark.vertex[(i + 1) % 4][0];
		yd = Mark.vertex[i][1] - Mark.vertex[(i + 1) % 4][1];
		dd = sqrt(xd*xd + yd*yd);
		ddAcc = ddAcc + dd;
	}
	return ddAcc / 4.0;
}
void DetctQrcode::loopClear()
{
	detectedID.clear();
	ID_X.clear();
	ID_Y.clear();
	side_size.clear();
	ID_Theta.clear();
	//thresholds.clear();
	MarkerPrototypes.clear();
	pan_res_acc.clear();
	QrMarks.clear();
	coners.clear();
	coners_aver.clear();
}
void DetctQrcode::trackerFunction(TrackerSingleMarker *ptrackerFast)
{
	ptrackerFast->setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_LUM);
	// load a camera file.
	if (!ptrackerFast->init("./data/no_distortion.cal", 1.0f, 1000.0f)) // load MATLAB file
	{
		printf("ERROR: init() failed\n");
	}
	ptrackerFast->setPatternWidth(2.0);
	ptrackerFast->setBorderWidth(useBCH ? 0.125 : 0.25);    //  const bool useBCH = false;
	ptrackerFast->setUndistortionMode(ARToolKitPlus::UNDIST_LUT);
	ptrackerFast->setMarkerMode(useBCH ? ARToolKitPlus::MARKER_ID_BCH : ARToolKitPlus::MARKER_ID_SIMPLE);
	//ptrackerFast->setNumAutoThresholdRetries(1000);
	/// Turns automatic threshold calculation on/off
	ptrackerFast->activateAutoThreshold(true);
	ptrackerFast->setNumAutoThresholdRetries(1000);
}
void DetctQrcode::computePose(void)
{
	cv::Mat Rvec;
	cv::Mat_<float> Tvec;
	cv::Mat raux, taux;

	cv::solvePnP(points3d_, points2d_, camera_matrix_, distcoeffs_, raux, taux);

	raux.convertTo(Rvec, CV_32F);
	taux.convertTo(Tvec, CV_32F);

	cout << "raux.cols raux.rows :" << Rvec.cols << "  " << Rvec.rows << endl;
	cout << "raux.cols raux.rows :" << Rvec << "  " << endl;

//	cv::Mat_<float> rotMat(3, 3);

//	cv::Rodrigues(Rvec, rotMat);//Converts a rotation matrix to a rotation vector or vice versa.
//	// Copy to transformation matrix
//	cout << "pose3d.r()" << endl;
//	for (int col = 0; col<3; col++)
//	{
//		for (int row = 0; row<3; row++)
//		{
//			pose3d.r().mat[row][col] = rotMat(row, col); // Copy rotation component
//			cout << "  " << rotMat(row, col) << "  ";
//		}
//		pose3d.t().data[col] = Tvec(col); // Copy translation component
//		cout << "  " << Tvec(col) << "  ";
//		cout << "  " << endl;
//	}
//   Since solvePnP finds camera location, w.r.t to marker pose, to get marker pose w.r.t to the camera we invert it.
//    pose3d = pose3d.getInverted();
    for(int i=0 ;i<3;++i)
    {
       r_[i] =  Rvec.at<float>(i,0)*180/3.1415926;
       t_[i] =  -1*Tvec.at<float>(i, 0) ;
    }

}


