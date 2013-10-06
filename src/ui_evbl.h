/********************************************************************************
** Form generated from reading UI file 'evbl.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVBL_H
#define UI_EVBL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cvimagewidget.h>

QT_BEGIN_NAMESPACE

class Ui_eVBL
{
public:
    QVBoxLayout *verticalLayout_8;
    QTabWidget *evbl_tabs;
    QWidget *capture_tab;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *capture_left_side;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *source_layout;
    QLabel *label_sauce;
    QComboBox *device_list;
    QHBoxLayout *Preview_vid_layout;
    QSpacerItem *horizontalSpacer_7;
    CVImageWidget *previewVideo;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *gain_layout;
    QLabel *label_gain;
    QSlider *gain_slider;
    QSpinBox *spin_gain;
    QHBoxLayout *exposure_layout;
    QLabel *label_exposure;
    QSlider *horizontalSlider_2;
    QSpinBox *spinBox_4;
    QGroupBox *capture_groupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *capture_button_layout;
    QPushButton *capture_frame_button;
    QPushButton *multi_frame_button;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_26;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_multishots;
    QSpacerItem *horizontalSpacer_25;
    QSpinBox *spin_multi;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_multishots2;
    QSpacerItem *horizontalSpacer_18;
    QLabel *multishot_status;
    QSpacerItem *horizontalSpacer_27;
    QGroupBox *filename_groupBox;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_15;
    QVBoxLayout *Filename_layout_group;
    QHBoxLayout *Filename_layout_1;
    QLabel *label_initials;
    QLineEdit *info_initials;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *Filename_layout_2;
    QLabel *label_school;
    QLineEdit *info_school;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *Filename_layout_3;
    QLabel *label_object;
    QComboBox *combo_object;
    QSpacerItem *horizontalSpacer;
    QLabel *label_distance;
    QLineEdit *info_distance;
    QLabel *label_mm;
    QHBoxLayout *Filename_layout_4;
    QLabel *label_wavelength;
    QComboBox *combo_wavelength;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_objectnumber;
    QComboBox *combo_objectnumber;
    QHBoxLayout *Filename_layout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *save_image_button;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_29;
    QVBoxLayout *capture_right_side;
    QHBoxLayout *capture_zoom_layout;
    QLabel *label_zoom;
    QComboBox *zoom_setting;
    QLabel *label_resolution;
    QSpacerItem *horizontalSpacer_10;
    QScrollArea *scrollArea_Capture;
    QWidget *capture_scrollarea;
    QHBoxLayout *horizontalLayout_14;
    CVImageWidget *captured_display;
    QHBoxLayout *horizontalLayout_22;
    QWidget *process_tab;
    QHBoxLayout *horizontalLayout_26;
    QVBoxLayout *process_left_side;
    QGroupBox *imge_load_group;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *open_analysis_button;
    QLabel *label_loaded_file;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *background_button;
    QLabel *label_loaded_background;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_background_warning;
    QSpacerItem *horizontalSpacer_22;
    QCheckBox *check_background;
    QGroupBox *anal_group;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *anal_type_tab;
    QWidget *length_tab;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_distance_measure;
    QLabel *label_3;
    QLabel *measured_distance;
    QWidget *angle_tab;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_angle;
    QSpacerItem *horizontalSpacer_30;
    QGroupBox *angle_units_group;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radio_degrees;
    QRadioButton *radio_radians;
    QLabel *label_4;
    QLabel *angle_measurement;
    QWidget *intensity_tab;
    QVBoxLayout *verticalLayout_12;
    CVImageWidget *intensity_display;
    QHBoxLayout *horizontalLayout_23;
    QSpacerItem *horizontalSpacer_36;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_rotate;
    QSlider *rotate_slider;
    QDoubleSpinBox *rotate_spinbox;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_31;
    QLabel *label_csvexport;
    QPushButton *file_button;
    QPushButton *clipboard_button;
    QWidget *crop_tab;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_33;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_19;
    QLabel *crop_info_label;
    QPushButton *crop_button;
    QSpacerItem *horizontalSpacer_32;
    QVBoxLayout *line_properties_layout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_line_properties;
    QSpacerItem *horizontalSpacer_24;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_line_colourt;
    QComboBox *combo_line_colour;
    QSpacerItem *horizontalSpacer_23;
    QLabel *label_line_thickness;
    QComboBox *combo_line_thickness;
    QLabel *label_line_pixels;
    QGroupBox *image_properties_group;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *colours_layout;
    QLabel *label_colours;
    QSpacerItem *horizontalSpacer_11;
    QCheckBox *check_invert;
    QCheckBox *check_bw;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *threshold_layout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_threshold;
    QSpacerItem *horizontalSpacer_17;
    QGridLayout *gridLayout;
    QLabel *label_lowpoint;
    QSlider *slider_low_point;
    QSpinBox *spin_low_point;
    QLabel *label_highpoint;
    QSlider *slider_high_point;
    QSpinBox *spin_high_point;
    QHBoxLayout *smoothing_layout;
    QLabel *label_smoothing;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_blur;
    QHBoxLayout *horizontalLayout;
    QCheckBox *check_gaussian;
    QSpinBox *spin_gauss;
    QLabel *label_pixels;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *reset_layout;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *reset_image;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_20;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_zoom_process;
    QComboBox *zoom_setting_process;
    QLabel *label_resolution_process;
    QSpacerItem *horizontalSpacer_28;
    QScrollArea *scrollArea_Analyse;
    QWidget *analyse_scrollarea;
    QHBoxLayout *horizontalLayout_21;
    CVImageWidget *analyse_display;
    QHBoxLayout *horizontalLayout_24;

    void setupUi(QWidget *eVBL)
    {
        if (eVBL->objectName().isEmpty())
            eVBL->setObjectName(QStringLiteral("eVBL"));
        eVBL->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eVBL->sizePolicy().hasHeightForWidth());
        eVBL->setSizePolicy(sizePolicy);
        eVBL->setMinimumSize(QSize(1640, 980));
        eVBL->setMaximumSize(QSize(1640, 980));
        eVBL->setBaseSize(QSize(0, 0));
        eVBL->setContextMenuPolicy(Qt::DefaultContextMenu);
        eVBL->setWindowFilePath(QStringLiteral(""));
        verticalLayout_8 = new QVBoxLayout(eVBL);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        evbl_tabs = new QTabWidget(eVBL);
        evbl_tabs->setObjectName(QStringLiteral("evbl_tabs"));
        evbl_tabs->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(evbl_tabs->sizePolicy().hasHeightForWidth());
        evbl_tabs->setSizePolicy(sizePolicy1);
        evbl_tabs->setMinimumSize(QSize(1640, 980));
        evbl_tabs->setMaximumSize(QSize(16777212, 16777215));
        evbl_tabs->setSizeIncrement(QSize(0, 0));
        evbl_tabs->setUsesScrollButtons(true);
        capture_tab = new QWidget();
        capture_tab->setObjectName(QStringLiteral("capture_tab"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(capture_tab->sizePolicy().hasHeightForWidth());
        capture_tab->setSizePolicy(sizePolicy2);
        horizontalLayout_27 = new QHBoxLayout(capture_tab);
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        capture_left_side = new QVBoxLayout();
        capture_left_side->setSpacing(6);
        capture_left_side->setObjectName(QStringLiteral("capture_left_side"));
        verticalSpacer_2 = new QSpacerItem(14, 15, QSizePolicy::Minimum, QSizePolicy::Minimum);

        capture_left_side->addItem(verticalSpacer_2);

        source_layout = new QHBoxLayout();
        source_layout->setSpacing(6);
        source_layout->setObjectName(QStringLiteral("source_layout"));
        label_sauce = new QLabel(capture_tab);
        label_sauce->setObjectName(QStringLiteral("label_sauce"));
        label_sauce->setMaximumSize(QSize(40, 16777215));
        QFont font;
        font.setPointSize(10);
        label_sauce->setFont(font);

        source_layout->addWidget(label_sauce);

        device_list = new QComboBox(capture_tab);
        device_list->setObjectName(QStringLiteral("device_list"));
        device_list->setMinimumSize(QSize(180, 0));

        source_layout->addWidget(device_list);


        capture_left_side->addLayout(source_layout);

        Preview_vid_layout = new QHBoxLayout();
        Preview_vid_layout->setSpacing(6);
        Preview_vid_layout->setObjectName(QStringLiteral("Preview_vid_layout"));
        horizontalSpacer_7 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Preview_vid_layout->addItem(horizontalSpacer_7);

        previewVideo = new CVImageWidget(capture_tab);
        previewVideo->setObjectName(QStringLiteral("previewVideo"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(previewVideo->sizePolicy().hasHeightForWidth());
        previewVideo->setSizePolicy(sizePolicy3);
        previewVideo->setMinimumSize(QSize(320, 240));
        previewVideo->setAutoFillBackground(true);
        horizontalLayout_5 = new QHBoxLayout(previewVideo);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        Preview_vid_layout->addWidget(previewVideo);

        horizontalSpacer_8 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Preview_vid_layout->addItem(horizontalSpacer_8);


        capture_left_side->addLayout(Preview_vid_layout);

        gain_layout = new QHBoxLayout();
        gain_layout->setSpacing(6);
        gain_layout->setObjectName(QStringLiteral("gain_layout"));
        gain_layout->setSizeConstraint(QLayout::SetFixedSize);
        label_gain = new QLabel(capture_tab);
        label_gain->setObjectName(QStringLiteral("label_gain"));
        sizePolicy3.setHeightForWidth(label_gain->sizePolicy().hasHeightForWidth());
        label_gain->setSizePolicy(sizePolicy3);
        label_gain->setMinimumSize(QSize(50, 20));
        label_gain->setMaximumSize(QSize(50, 16777215));

        gain_layout->addWidget(label_gain);

        gain_slider = new QSlider(capture_tab);
        gain_slider->setObjectName(QStringLiteral("gain_slider"));
        gain_slider->setEnabled(false);
        sizePolicy3.setHeightForWidth(gain_slider->sizePolicy().hasHeightForWidth());
        gain_slider->setSizePolicy(sizePolicy3);
        gain_slider->setMinimumSize(QSize(300, 20));
        gain_slider->setMaximumSize(QSize(320, 16777215));
        gain_slider->setOrientation(Qt::Horizontal);

        gain_layout->addWidget(gain_slider);

        spin_gain = new QSpinBox(capture_tab);
        spin_gain->setObjectName(QStringLiteral("spin_gain"));
        spin_gain->setEnabled(false);
        sizePolicy3.setHeightForWidth(spin_gain->sizePolicy().hasHeightForWidth());
        spin_gain->setSizePolicy(sizePolicy3);
        spin_gain->setMinimumSize(QSize(45, 20));
        spin_gain->setMaximumSize(QSize(45, 16777215));

        gain_layout->addWidget(spin_gain);


        capture_left_side->addLayout(gain_layout);

        exposure_layout = new QHBoxLayout();
        exposure_layout->setSpacing(6);
        exposure_layout->setObjectName(QStringLiteral("exposure_layout"));
        label_exposure = new QLabel(capture_tab);
        label_exposure->setObjectName(QStringLiteral("label_exposure"));
        sizePolicy3.setHeightForWidth(label_exposure->sizePolicy().hasHeightForWidth());
        label_exposure->setSizePolicy(sizePolicy3);
        label_exposure->setMinimumSize(QSize(50, 20));

        exposure_layout->addWidget(label_exposure);

        horizontalSlider_2 = new QSlider(capture_tab);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setEnabled(false);
        sizePolicy3.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy3);
        horizontalSlider_2->setMinimumSize(QSize(300, 20));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        exposure_layout->addWidget(horizontalSlider_2);

        spinBox_4 = new QSpinBox(capture_tab);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setEnabled(false);
        sizePolicy3.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy3);
        spinBox_4->setMinimumSize(QSize(45, 20));

        exposure_layout->addWidget(spinBox_4);


        capture_left_side->addLayout(exposure_layout);

        capture_groupBox = new QGroupBox(capture_tab);
        capture_groupBox->setObjectName(QStringLiteral("capture_groupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(capture_groupBox->sizePolicy().hasHeightForWidth());
        capture_groupBox->setSizePolicy(sizePolicy4);
        capture_groupBox->setMinimumSize(QSize(400, 0));
        verticalLayout_7 = new QVBoxLayout(capture_groupBox);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        capture_button_layout = new QHBoxLayout();
        capture_button_layout->setSpacing(6);
        capture_button_layout->setObjectName(QStringLiteral("capture_button_layout"));
        capture_frame_button = new QPushButton(capture_groupBox);
        capture_frame_button->setObjectName(QStringLiteral("capture_frame_button"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(capture_frame_button->sizePolicy().hasHeightForWidth());
        capture_frame_button->setSizePolicy(sizePolicy5);
        capture_frame_button->setMinimumSize(QSize(0, 50));
        capture_frame_button->setMaximumSize(QSize(210, 16777215));
        QFont font1;
        font1.setPointSize(12);
        capture_frame_button->setFont(font1);

        capture_button_layout->addWidget(capture_frame_button);

        multi_frame_button = new QPushButton(capture_groupBox);
        multi_frame_button->setObjectName(QStringLiteral("multi_frame_button"));
        sizePolicy5.setHeightForWidth(multi_frame_button->sizePolicy().hasHeightForWidth());
        multi_frame_button->setSizePolicy(sizePolicy5);
        multi_frame_button->setMinimumSize(QSize(0, 50));
        multi_frame_button->setMaximumSize(QSize(210, 16777215));
        multi_frame_button->setFont(font1);

        capture_button_layout->addWidget(multi_frame_button);


        verticalLayout_7->addLayout(capture_button_layout);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_26);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_multishots = new QLabel(capture_groupBox);
        label_multishots->setObjectName(QStringLiteral("label_multishots"));
        label_multishots->setFont(font1);

        horizontalLayout_13->addWidget(label_multishots);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_25);

        spin_multi = new QSpinBox(capture_groupBox);
        spin_multi->setObjectName(QStringLiteral("spin_multi"));
        spin_multi->setMinimumSize(QSize(50, 30));
        spin_multi->setFont(font1);
        spin_multi->setAlignment(Qt::AlignCenter);
        spin_multi->setMinimum(2);
        spin_multi->setMaximum(10);
        spin_multi->setValue(5);

        horizontalLayout_13->addWidget(spin_multi);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_multishots2 = new QLabel(capture_groupBox);
        label_multishots2->setObjectName(QStringLiteral("label_multishots2"));
        sizePolicy3.setHeightForWidth(label_multishots2->sizePolicy().hasHeightForWidth());
        label_multishots2->setSizePolicy(sizePolicy3);
        label_multishots2->setFont(font1);

        horizontalLayout_12->addWidget(label_multishots2);

        horizontalSpacer_18 = new QSpacerItem(40, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_18);

        multishot_status = new QLabel(capture_groupBox);
        multishot_status->setObjectName(QStringLiteral("multishot_status"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(multishot_status->sizePolicy().hasHeightForWidth());
        multishot_status->setSizePolicy(sizePolicy6);
        multishot_status->setMinimumSize(QSize(90, 30));
        multishot_status->setFont(font1);
        multishot_status->setFrameShape(QFrame::Box);
        multishot_status->setAlignment(Qt::AlignCenter);
        multishot_status->setMargin(4);
        multishot_status->setIndent(-1);

        horizontalLayout_12->addWidget(multishot_status);


        verticalLayout_6->addLayout(horizontalLayout_12);


        horizontalLayout_15->addLayout(verticalLayout_6);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_27);


        verticalLayout_7->addLayout(horizontalLayout_15);


        capture_left_side->addWidget(capture_groupBox);

        filename_groupBox = new QGroupBox(capture_tab);
        filename_groupBox->setObjectName(QStringLiteral("filename_groupBox"));
        sizePolicy4.setHeightForWidth(filename_groupBox->sizePolicy().hasHeightForWidth());
        filename_groupBox->setSizePolicy(sizePolicy4);
        filename_groupBox->setMinimumSize(QSize(400, 0));
        horizontalLayout_16 = new QHBoxLayout(filename_groupBox);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalSpacer_15 = new QSpacerItem(33, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_15);

        Filename_layout_group = new QVBoxLayout();
        Filename_layout_group->setSpacing(6);
        Filename_layout_group->setObjectName(QStringLiteral("Filename_layout_group"));
        Filename_layout_1 = new QHBoxLayout();
        Filename_layout_1->setSpacing(6);
        Filename_layout_1->setObjectName(QStringLiteral("Filename_layout_1"));
        label_initials = new QLabel(filename_groupBox);
        label_initials->setObjectName(QStringLiteral("label_initials"));
        sizePolicy3.setHeightForWidth(label_initials->sizePolicy().hasHeightForWidth());
        label_initials->setSizePolicy(sizePolicy3);
        label_initials->setMaximumSize(QSize(40, 16777215));
        label_initials->setFont(font);
        label_initials->setTextFormat(Qt::AutoText);
        label_initials->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Filename_layout_1->addWidget(label_initials);

        info_initials = new QLineEdit(filename_groupBox);
        info_initials->setObjectName(QStringLiteral("info_initials"));
        sizePolicy3.setHeightForWidth(info_initials->sizePolicy().hasHeightForWidth());
        info_initials->setSizePolicy(sizePolicy3);
        info_initials->setMaximumSize(QSize(50, 16777215));

        Filename_layout_1->addWidget(info_initials);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Filename_layout_1->addItem(horizontalSpacer_3);


        Filename_layout_group->addLayout(Filename_layout_1);

        Filename_layout_2 = new QHBoxLayout();
        Filename_layout_2->setSpacing(6);
        Filename_layout_2->setObjectName(QStringLiteral("Filename_layout_2"));
        label_school = new QLabel(filename_groupBox);
        label_school->setObjectName(QStringLiteral("label_school"));
        label_school->setMaximumSize(QSize(40, 16777215));
        label_school->setFont(font);
        label_school->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Filename_layout_2->addWidget(label_school);

        info_school = new QLineEdit(filename_groupBox);
        info_school->setObjectName(QStringLiteral("info_school"));
        sizePolicy3.setHeightForWidth(info_school->sizePolicy().hasHeightForWidth());
        info_school->setSizePolicy(sizePolicy3);
        info_school->setMinimumSize(QSize(200, 0));
        info_school->setMaximumSize(QSize(200, 16777215));

        Filename_layout_2->addWidget(info_school);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Filename_layout_2->addItem(horizontalSpacer_4);


        Filename_layout_group->addLayout(Filename_layout_2);

        Filename_layout_3 = new QHBoxLayout();
        Filename_layout_3->setSpacing(6);
        Filename_layout_3->setObjectName(QStringLiteral("Filename_layout_3"));
        label_object = new QLabel(filename_groupBox);
        label_object->setObjectName(QStringLiteral("label_object"));
        label_object->setMinimumSize(QSize(0, 0));
        label_object->setMaximumSize(QSize(40, 16777215));
        label_object->setFont(font);
        label_object->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Filename_layout_3->addWidget(label_object);

        combo_object = new QComboBox(filename_groupBox);
        combo_object->setObjectName(QStringLiteral("combo_object"));
        sizePolicy3.setHeightForWidth(combo_object->sizePolicy().hasHeightForWidth());
        combo_object->setSizePolicy(sizePolicy3);
        combo_object->setMinimumSize(QSize(80, 0));
        combo_object->setMaximumSize(QSize(80, 16777215));

        Filename_layout_3->addWidget(combo_object);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Filename_layout_3->addItem(horizontalSpacer);

        label_distance = new QLabel(filename_groupBox);
        label_distance->setObjectName(QStringLiteral("label_distance"));
        label_distance->setMinimumSize(QSize(50, 0));
        label_distance->setMaximumSize(QSize(50, 16777215));
        label_distance->setFont(font);
        label_distance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Filename_layout_3->addWidget(label_distance);

        info_distance = new QLineEdit(filename_groupBox);
        info_distance->setObjectName(QStringLiteral("info_distance"));
        sizePolicy3.setHeightForWidth(info_distance->sizePolicy().hasHeightForWidth());
        info_distance->setSizePolicy(sizePolicy3);
        info_distance->setMinimumSize(QSize(40, 0));
        info_distance->setMaximumSize(QSize(40, 16777215));

        Filename_layout_3->addWidget(info_distance);

        label_mm = new QLabel(filename_groupBox);
        label_mm->setObjectName(QStringLiteral("label_mm"));
        label_mm->setMinimumSize(QSize(20, 0));
        label_mm->setMaximumSize(QSize(20, 16777215));

        Filename_layout_3->addWidget(label_mm);


        Filename_layout_group->addLayout(Filename_layout_3);

        Filename_layout_4 = new QHBoxLayout();
        Filename_layout_4->setSpacing(6);
        Filename_layout_4->setObjectName(QStringLiteral("Filename_layout_4"));
        label_wavelength = new QLabel(filename_groupBox);
        label_wavelength->setObjectName(QStringLiteral("label_wavelength"));
        label_wavelength->setMaximumSize(QSize(65, 16777215));
        label_wavelength->setFont(font);
        label_wavelength->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Filename_layout_4->addWidget(label_wavelength);

        combo_wavelength = new QComboBox(filename_groupBox);
        combo_wavelength->setObjectName(QStringLiteral("combo_wavelength"));
        sizePolicy3.setHeightForWidth(combo_wavelength->sizePolicy().hasHeightForWidth());
        combo_wavelength->setSizePolicy(sizePolicy3);
        combo_wavelength->setMinimumSize(QSize(60, 0));
        combo_wavelength->setMaximumSize(QSize(60, 16777215));

        Filename_layout_4->addWidget(combo_wavelength);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Filename_layout_4->addItem(horizontalSpacer_2);

        label_objectnumber = new QLabel(filename_groupBox);
        label_objectnumber->setObjectName(QStringLiteral("label_objectnumber"));
        label_objectnumber->setMaximumSize(QSize(85, 16777215));
        label_objectnumber->setFont(font);
        label_objectnumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Filename_layout_4->addWidget(label_objectnumber);

        combo_objectnumber = new QComboBox(filename_groupBox);
        combo_objectnumber->setObjectName(QStringLiteral("combo_objectnumber"));
        sizePolicy3.setHeightForWidth(combo_objectnumber->sizePolicy().hasHeightForWidth());
        combo_objectnumber->setSizePolicy(sizePolicy3);
        combo_objectnumber->setMinimumSize(QSize(30, 0));
        combo_objectnumber->setMaximumSize(QSize(30, 16777215));

        Filename_layout_4->addWidget(combo_objectnumber);


        Filename_layout_group->addLayout(Filename_layout_4);

        Filename_layout_5 = new QHBoxLayout();
        Filename_layout_5->setSpacing(6);
        Filename_layout_5->setObjectName(QStringLiteral("Filename_layout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Filename_layout_5->addItem(horizontalSpacer_5);

        save_image_button = new QPushButton(filename_groupBox);
        save_image_button->setObjectName(QStringLiteral("save_image_button"));
        sizePolicy3.setHeightForWidth(save_image_button->sizePolicy().hasHeightForWidth());
        save_image_button->setSizePolicy(sizePolicy3);
        save_image_button->setMinimumSize(QSize(200, 50));
        save_image_button->setFont(font);

        Filename_layout_5->addWidget(save_image_button);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Filename_layout_5->addItem(horizontalSpacer_6);


        Filename_layout_group->addLayout(Filename_layout_5);


        horizontalLayout_16->addLayout(Filename_layout_group);

        horizontalSpacer_9 = new QSpacerItem(33, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);


        capture_left_side->addWidget(filename_groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        capture_left_side->addItem(verticalSpacer_3);


        horizontalLayout_27->addLayout(capture_left_side);

        horizontalSpacer_29 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_29);

        capture_right_side = new QVBoxLayout();
        capture_right_side->setSpacing(6);
        capture_right_side->setObjectName(QStringLiteral("capture_right_side"));
        capture_zoom_layout = new QHBoxLayout();
        capture_zoom_layout->setSpacing(6);
        capture_zoom_layout->setObjectName(QStringLiteral("capture_zoom_layout"));
        label_zoom = new QLabel(capture_tab);
        label_zoom->setObjectName(QStringLiteral("label_zoom"));
        sizePolicy5.setHeightForWidth(label_zoom->sizePolicy().hasHeightForWidth());
        label_zoom->setSizePolicy(sizePolicy5);
        label_zoom->setMinimumSize(QSize(40, 20));
        label_zoom->setMaximumSize(QSize(30, 16777215));
        label_zoom->setFont(font);

        capture_zoom_layout->addWidget(label_zoom);

        zoom_setting = new QComboBox(capture_tab);
        zoom_setting->setObjectName(QStringLiteral("zoom_setting"));
        zoom_setting->setEnabled(true);
        zoom_setting->setMinimumSize(QSize(70, 20));
        zoom_setting->setMaximumSize(QSize(70, 16777215));
        zoom_setting->setEditable(false);

        capture_zoom_layout->addWidget(zoom_setting);

        label_resolution = new QLabel(capture_tab);
        label_resolution->setObjectName(QStringLiteral("label_resolution"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_resolution->sizePolicy().hasHeightForWidth());
        label_resolution->setSizePolicy(sizePolicy7);
        label_resolution->setMinimumSize(QSize(100, 20));
        label_resolution->setMaximumSize(QSize(200, 16777215));

        capture_zoom_layout->addWidget(label_resolution);

        horizontalSpacer_10 = new QSpacerItem(638, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        capture_zoom_layout->addItem(horizontalSpacer_10);


        capture_right_side->addLayout(capture_zoom_layout);

        scrollArea_Capture = new QScrollArea(capture_tab);
        scrollArea_Capture->setObjectName(QStringLiteral("scrollArea_Capture"));
        sizePolicy.setHeightForWidth(scrollArea_Capture->sizePolicy().hasHeightForWidth());
        scrollArea_Capture->setSizePolicy(sizePolicy);
        scrollArea_Capture->setMinimumSize(QSize(1200, 900));
        scrollArea_Capture->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_Capture->setLineWidth(2);
        scrollArea_Capture->setWidgetResizable(true);
        scrollArea_Capture->setAlignment(Qt::AlignCenter);
        capture_scrollarea = new QWidget();
        capture_scrollarea->setObjectName(QStringLiteral("capture_scrollarea"));
        capture_scrollarea->setGeometry(QRect(0, 0, 1198, 898));
        sizePolicy.setHeightForWidth(capture_scrollarea->sizePolicy().hasHeightForWidth());
        capture_scrollarea->setSizePolicy(sizePolicy);
        capture_scrollarea->setMinimumSize(QSize(0, 0));
        horizontalLayout_14 = new QHBoxLayout(capture_scrollarea);
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        captured_display = new CVImageWidget(capture_scrollarea);
        captured_display->setObjectName(QStringLiteral("captured_display"));
        sizePolicy3.setHeightForWidth(captured_display->sizePolicy().hasHeightForWidth());
        captured_display->setSizePolicy(sizePolicy3);
        captured_display->setMinimumSize(QSize(0, 0));
        captured_display->setBaseSize(QSize(0, 0));
        captured_display->setAutoFillBackground(true);
        horizontalLayout_22 = new QHBoxLayout(captured_display);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_14->addWidget(captured_display);

        scrollArea_Capture->setWidget(capture_scrollarea);

        capture_right_side->addWidget(scrollArea_Capture);


        horizontalLayout_27->addLayout(capture_right_side);

        evbl_tabs->addTab(capture_tab, QString());
        spin_multi->raise();
        label_multishots->raise();
        label_multishots2->raise();
        multishot_status->raise();
        save_image_button->raise();
        filename_groupBox->raise();
        capture_groupBox->raise();
        process_tab = new QWidget();
        process_tab->setObjectName(QStringLiteral("process_tab"));
        sizePolicy2.setHeightForWidth(process_tab->sizePolicy().hasHeightForWidth());
        process_tab->setSizePolicy(sizePolicy2);
        horizontalLayout_26 = new QHBoxLayout(process_tab);
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        process_left_side = new QVBoxLayout();
        process_left_side->setSpacing(6);
        process_left_side->setObjectName(QStringLiteral("process_left_side"));
        imge_load_group = new QGroupBox(process_tab);
        imge_load_group->setObjectName(QStringLiteral("imge_load_group"));
        sizePolicy4.setHeightForWidth(imge_load_group->sizePolicy().hasHeightForWidth());
        imge_load_group->setSizePolicy(sizePolicy4);
        imge_load_group->setMinimumSize(QSize(400, 150));
        imge_load_group->setFont(font1);
        verticalLayout_3 = new QVBoxLayout(imge_load_group);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        open_analysis_button = new QPushButton(imge_load_group);
        open_analysis_button->setObjectName(QStringLiteral("open_analysis_button"));
        sizePolicy5.setHeightForWidth(open_analysis_button->sizePolicy().hasHeightForWidth());
        open_analysis_button->setSizePolicy(sizePolicy5);
        open_analysis_button->setMinimumSize(QSize(120, 30));
        open_analysis_button->setFont(font);

        horizontalLayout_10->addWidget(open_analysis_button);

        label_loaded_file = new QLabel(imge_load_group);
        label_loaded_file->setObjectName(QStringLiteral("label_loaded_file"));
        QFont font2;
        font2.setPointSize(8);
        label_loaded_file->setFont(font2);

        horizontalLayout_10->addWidget(label_loaded_file);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_19);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        background_button = new QPushButton(imge_load_group);
        background_button->setObjectName(QStringLiteral("background_button"));
        sizePolicy5.setHeightForWidth(background_button->sizePolicy().hasHeightForWidth());
        background_button->setSizePolicy(sizePolicy5);
        background_button->setMinimumSize(QSize(120, 30));
        background_button->setFont(font);

        horizontalLayout_4->addWidget(background_button);

        label_loaded_background = new QLabel(imge_load_group);
        label_loaded_background->setObjectName(QStringLiteral("label_loaded_background"));
        sizePolicy.setHeightForWidth(label_loaded_background->sizePolicy().hasHeightForWidth());
        label_loaded_background->setSizePolicy(sizePolicy);
        label_loaded_background->setFont(font2);

        horizontalLayout_4->addWidget(label_loaded_background);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_21);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_background_warning = new QLabel(imge_load_group);
        label_background_warning->setObjectName(QStringLiteral("label_background_warning"));

        horizontalLayout_2->addWidget(label_background_warning);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_22);

        check_background = new QCheckBox(imge_load_group);
        check_background->setObjectName(QStringLiteral("check_background"));
        check_background->setFont(font1);
        check_background->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(check_background);


        verticalLayout_3->addLayout(horizontalLayout_2);


        process_left_side->addWidget(imge_load_group);

        anal_group = new QGroupBox(process_tab);
        anal_group->setObjectName(QStringLiteral("anal_group"));
        sizePolicy4.setHeightForWidth(anal_group->sizePolicy().hasHeightForWidth());
        anal_group->setSizePolicy(sizePolicy4);
        anal_group->setMinimumSize(QSize(400, 360));
        anal_group->setFont(font1);
        verticalLayout_4 = new QVBoxLayout(anal_group);
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        anal_type_tab = new QTabWidget(anal_group);
        anal_type_tab->setObjectName(QStringLiteral("anal_type_tab"));
        QSizePolicy sizePolicy8(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(anal_type_tab->sizePolicy().hasHeightForWidth());
        anal_type_tab->setSizePolicy(sizePolicy8);
        anal_type_tab->setMinimumSize(QSize(400, 220));
        anal_type_tab->setFont(font2);
        length_tab = new QWidget();
        length_tab->setObjectName(QStringLiteral("length_tab"));
        length_tab->setAutoFillBackground(false);
        verticalLayout_13 = new QVBoxLayout(length_tab);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_distance_measure = new QLabel(length_tab);
        label_distance_measure->setObjectName(QStringLiteral("label_distance_measure"));
        label_distance_measure->setMinimumSize(QSize(0, 30));
        label_distance_measure->setMaximumSize(QSize(16777215, 20));
        QFont font3;
        font3.setPointSize(18);
        label_distance_measure->setFont(font3);

        verticalLayout_13->addWidget(label_distance_measure);

        label_3 = new QLabel(length_tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_13->addWidget(label_3);

        measured_distance = new QLabel(length_tab);
        measured_distance->setObjectName(QStringLiteral("measured_distance"));
        sizePolicy3.setHeightForWidth(measured_distance->sizePolicy().hasHeightForWidth());
        measured_distance->setSizePolicy(sizePolicy3);
        measured_distance->setMinimumSize(QSize(370, 100));
        QFont font4;
        font4.setPointSize(32);
        measured_distance->setFont(font4);
        measured_distance->setFrameShape(QFrame::Box);

        verticalLayout_13->addWidget(measured_distance);

        anal_type_tab->addTab(length_tab, QString());
        angle_tab = new QWidget();
        angle_tab->setObjectName(QStringLiteral("angle_tab"));
        verticalLayout_11 = new QVBoxLayout(angle_tab);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_angle = new QLabel(angle_tab);
        label_angle->setObjectName(QStringLiteral("label_angle"));
        label_angle->setMinimumSize(QSize(0, 30));
        label_angle->setFont(font3);

        horizontalLayout_11->addWidget(label_angle);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_30);

        angle_units_group = new QGroupBox(angle_tab);
        angle_units_group->setObjectName(QStringLiteral("angle_units_group"));
        angle_units_group->setMinimumSize(QSize(0, 50));
        angle_units_group->setFont(font2);
        horizontalLayout_6 = new QHBoxLayout(angle_units_group);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        radio_degrees = new QRadioButton(angle_units_group);
        radio_degrees->setObjectName(QStringLiteral("radio_degrees"));
        radio_degrees->setChecked(true);

        horizontalLayout_6->addWidget(radio_degrees);

        radio_radians = new QRadioButton(angle_units_group);
        radio_radians->setObjectName(QStringLiteral("radio_radians"));

        horizontalLayout_6->addWidget(radio_radians);


        horizontalLayout_11->addWidget(angle_units_group);


        verticalLayout_11->addLayout(horizontalLayout_11);

        label_4 = new QLabel(angle_tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_11->addWidget(label_4);

        angle_measurement = new QLabel(angle_tab);
        angle_measurement->setObjectName(QStringLiteral("angle_measurement"));
        angle_measurement->setMinimumSize(QSize(370, 100));
        angle_measurement->setFont(font4);
        angle_measurement->setFrameShape(QFrame::Box);

        verticalLayout_11->addWidget(angle_measurement);

        anal_type_tab->addTab(angle_tab, QString());
        intensity_tab = new QWidget();
        intensity_tab->setObjectName(QStringLiteral("intensity_tab"));
        verticalLayout_12 = new QVBoxLayout(intensity_tab);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        intensity_display = new CVImageWidget(intensity_tab);
        intensity_display->setObjectName(QStringLiteral("intensity_display"));
        sizePolicy.setHeightForWidth(intensity_display->sizePolicy().hasHeightForWidth());
        intensity_display->setSizePolicy(sizePolicy);
        intensity_display->setMinimumSize(QSize(370, 100));
        intensity_display->setBaseSize(QSize(0, 0));
        intensity_display->setAutoFillBackground(true);
        horizontalLayout_23 = new QHBoxLayout(intensity_display);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalSpacer_36 = new QSpacerItem(355, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_36);


        verticalLayout_12->addWidget(intensity_display);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_rotate = new QLabel(intensity_tab);
        label_rotate->setObjectName(QStringLiteral("label_rotate"));

        horizontalLayout_17->addWidget(label_rotate);

        rotate_slider = new QSlider(intensity_tab);
        rotate_slider->setObjectName(QStringLiteral("rotate_slider"));
        rotate_slider->setMinimum(-900);
        rotate_slider->setMaximum(900);
        rotate_slider->setSingleStep(1);
        rotate_slider->setPageStep(100);
        rotate_slider->setTracking(true);
        rotate_slider->setOrientation(Qt::Horizontal);
        rotate_slider->setInvertedControls(false);

        horizontalLayout_17->addWidget(rotate_slider);

        rotate_spinbox = new QDoubleSpinBox(intensity_tab);
        rotate_spinbox->setObjectName(QStringLiteral("rotate_spinbox"));
        sizePolicy3.setHeightForWidth(rotate_spinbox->sizePolicy().hasHeightForWidth());
        rotate_spinbox->setSizePolicy(sizePolicy3);
        rotate_spinbox->setDecimals(1);
        rotate_spinbox->setMinimum(-90);
        rotate_spinbox->setMaximum(90);
        rotate_spinbox->setSingleStep(0.1);

        horizontalLayout_17->addWidget(rotate_spinbox);


        verticalLayout_12->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_31);

        label_csvexport = new QLabel(intensity_tab);
        label_csvexport->setObjectName(QStringLiteral("label_csvexport"));

        horizontalLayout_18->addWidget(label_csvexport);

        file_button = new QPushButton(intensity_tab);
        file_button->setObjectName(QStringLiteral("file_button"));

        horizontalLayout_18->addWidget(file_button);

        clipboard_button = new QPushButton(intensity_tab);
        clipboard_button->setObjectName(QStringLiteral("clipboard_button"));

        horizontalLayout_18->addWidget(clipboard_button);


        verticalLayout_12->addLayout(horizontalLayout_18);

        anal_type_tab->addTab(intensity_tab, QString());
        crop_tab = new QWidget();
        crop_tab->setObjectName(QStringLiteral("crop_tab"));
        verticalLayout_10 = new QVBoxLayout(crop_tab);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_5);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_2 = new QLabel(crop_tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_20->addWidget(label_2);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_33);


        verticalLayout_10->addLayout(horizontalLayout_20);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        crop_info_label = new QLabel(crop_tab);
        crop_info_label->setObjectName(QStringLiteral("crop_info_label"));
        crop_info_label->setFont(font);

        horizontalLayout_19->addWidget(crop_info_label);

        crop_button = new QPushButton(crop_tab);
        crop_button->setObjectName(QStringLiteral("crop_button"));
        crop_button->setMinimumSize(QSize(0, 30));

        horizontalLayout_19->addWidget(crop_button);


        verticalLayout_10->addLayout(horizontalLayout_19);

        horizontalSpacer_32 = new QSpacerItem(373, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_10->addItem(horizontalSpacer_32);

        anal_type_tab->addTab(crop_tab, QString());

        verticalLayout_4->addWidget(anal_type_tab);

        line_properties_layout = new QVBoxLayout();
        line_properties_layout->setSpacing(6);
        line_properties_layout->setObjectName(QStringLiteral("line_properties_layout"));
        line_properties_layout->setContentsMargins(0, 10, -1, 10);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_line_properties = new QLabel(anal_group);
        label_line_properties->setObjectName(QStringLiteral("label_line_properties"));
        label_line_properties->setMinimumSize(QSize(90, 0));
        label_line_properties->setFont(font);

        horizontalLayout_8->addWidget(label_line_properties);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_24);


        line_properties_layout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_line_colourt = new QLabel(anal_group);
        label_line_colourt->setObjectName(QStringLiteral("label_line_colourt"));
        label_line_colourt->setMinimumSize(QSize(40, 0));
        label_line_colourt->setFont(font2);

        horizontalLayout_7->addWidget(label_line_colourt);

        combo_line_colour = new QComboBox(anal_group);
        combo_line_colour->setObjectName(QStringLiteral("combo_line_colour"));
        combo_line_colour->setMinimumSize(QSize(150, 0));
        combo_line_colour->setFont(font2);
        combo_line_colour->setIconSize(QSize(16, 16));
        combo_line_colour->setFrame(true);

        horizontalLayout_7->addWidget(combo_line_colour);

        horizontalSpacer_23 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_23);

        label_line_thickness = new QLabel(anal_group);
        label_line_thickness->setObjectName(QStringLiteral("label_line_thickness"));
        label_line_thickness->setMinimumSize(QSize(55, 0));
        label_line_thickness->setFont(font2);

        horizontalLayout_7->addWidget(label_line_thickness);

        combo_line_thickness = new QComboBox(anal_group);
        combo_line_thickness->setObjectName(QStringLiteral("combo_line_thickness"));
        combo_line_thickness->setMinimumSize(QSize(30, 0));
        combo_line_thickness->setFont(font2);

        horizontalLayout_7->addWidget(combo_line_thickness);

        label_line_pixels = new QLabel(anal_group);
        label_line_pixels->setObjectName(QStringLiteral("label_line_pixels"));
        label_line_pixels->setMinimumSize(QSize(35, 0));
        label_line_pixels->setFont(font2);

        horizontalLayout_7->addWidget(label_line_pixels);


        line_properties_layout->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(line_properties_layout);


        process_left_side->addWidget(anal_group);

        image_properties_group = new QGroupBox(process_tab);
        image_properties_group->setObjectName(QStringLiteral("image_properties_group"));
        sizePolicy4.setHeightForWidth(image_properties_group->sizePolicy().hasHeightForWidth());
        image_properties_group->setSizePolicy(sizePolicy4);
        image_properties_group->setMinimumSize(QSize(400, 280));
        image_properties_group->setFont(font1);
        image_properties_group->setFlat(false);
        image_properties_group->setCheckable(false);
        verticalLayout_5 = new QVBoxLayout(image_properties_group);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        colours_layout = new QHBoxLayout();
        colours_layout->setSpacing(6);
        colours_layout->setObjectName(QStringLiteral("colours_layout"));
        label_colours = new QLabel(image_properties_group);
        label_colours->setObjectName(QStringLiteral("label_colours"));
        label_colours->setFont(font);

        colours_layout->addWidget(label_colours);

        horizontalSpacer_11 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        colours_layout->addItem(horizontalSpacer_11);

        check_invert = new QCheckBox(image_properties_group);
        check_invert->setObjectName(QStringLiteral("check_invert"));
        check_invert->setFont(font2);

        colours_layout->addWidget(check_invert);

        check_bw = new QCheckBox(image_properties_group);
        check_bw->setObjectName(QStringLiteral("check_bw"));
        check_bw->setFont(font2);

        colours_layout->addWidget(check_bw);

        horizontalSpacer_12 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        colours_layout->addItem(horizontalSpacer_12);


        verticalLayout_5->addLayout(colours_layout);

        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        threshold_layout = new QVBoxLayout();
        threshold_layout->setSpacing(6);
        threshold_layout->setObjectName(QStringLiteral("threshold_layout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_threshold = new QLabel(image_properties_group);
        label_threshold->setObjectName(QStringLiteral("label_threshold"));
        label_threshold->setFont(font);

        horizontalLayout_3->addWidget(label_threshold);

        horizontalSpacer_17 = new QSpacerItem(318, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_17);


        threshold_layout->addLayout(horizontalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_lowpoint = new QLabel(image_properties_group);
        label_lowpoint->setObjectName(QStringLiteral("label_lowpoint"));
        label_lowpoint->setMinimumSize(QSize(30, 0));
        label_lowpoint->setFont(font2);

        gridLayout->addWidget(label_lowpoint, 0, 0, 1, 1);

        slider_low_point = new QSlider(image_properties_group);
        slider_low_point->setObjectName(QStringLiteral("slider_low_point"));
        slider_low_point->setMinimum(0);
        slider_low_point->setMaximum(245);
        slider_low_point->setValue(0);
        slider_low_point->setTracking(false);
        slider_low_point->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_low_point, 0, 1, 1, 1);

        spin_low_point = new QSpinBox(image_properties_group);
        spin_low_point->setObjectName(QStringLiteral("spin_low_point"));
        spin_low_point->setEnabled(true);
        spin_low_point->setMinimumSize(QSize(50, 0));
        spin_low_point->setFont(font2);
        spin_low_point->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spin_low_point->setMaximum(245);

        gridLayout->addWidget(spin_low_point, 0, 2, 1, 1);

        label_highpoint = new QLabel(image_properties_group);
        label_highpoint->setObjectName(QStringLiteral("label_highpoint"));
        label_highpoint->setFont(font2);

        gridLayout->addWidget(label_highpoint, 1, 0, 1, 1);

        slider_high_point = new QSlider(image_properties_group);
        slider_high_point->setObjectName(QStringLiteral("slider_high_point"));
        slider_high_point->setMinimum(10);
        slider_high_point->setMaximum(255);
        slider_high_point->setValue(255);
        slider_high_point->setTracking(false);
        slider_high_point->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_high_point, 1, 1, 1, 1);

        spin_high_point = new QSpinBox(image_properties_group);
        spin_high_point->setObjectName(QStringLiteral("spin_high_point"));
        sizePolicy3.setHeightForWidth(spin_high_point->sizePolicy().hasHeightForWidth());
        spin_high_point->setSizePolicy(sizePolicy3);
        spin_high_point->setMinimumSize(QSize(50, 0));
        spin_high_point->setFont(font2);
        spin_high_point->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spin_high_point->setMinimum(10);
        spin_high_point->setMaximum(255);
        spin_high_point->setValue(255);

        gridLayout->addWidget(spin_high_point, 1, 2, 1, 1);


        threshold_layout->addLayout(gridLayout);


        verticalLayout_5->addLayout(threshold_layout);

        smoothing_layout = new QHBoxLayout();
        smoothing_layout->setSpacing(6);
        smoothing_layout->setObjectName(QStringLiteral("smoothing_layout"));
        label_smoothing = new QLabel(image_properties_group);
        label_smoothing->setObjectName(QStringLiteral("label_smoothing"));
        label_smoothing->setFont(font);

        smoothing_layout->addWidget(label_smoothing);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_blur = new QLabel(image_properties_group);
        label_blur->setObjectName(QStringLiteral("label_blur"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_blur->sizePolicy().hasHeightForWidth());
        label_blur->setSizePolicy(sizePolicy9);
        label_blur->setFont(font);

        verticalLayout_2->addWidget(label_blur);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        check_gaussian = new QCheckBox(image_properties_group);
        check_gaussian->setObjectName(QStringLiteral("check_gaussian"));
        sizePolicy9.setHeightForWidth(check_gaussian->sizePolicy().hasHeightForWidth());
        check_gaussian->setSizePolicy(sizePolicy9);
        check_gaussian->setFont(font2);

        horizontalLayout->addWidget(check_gaussian);

        spin_gauss = new QSpinBox(image_properties_group);
        spin_gauss->setObjectName(QStringLiteral("spin_gauss"));
        sizePolicy9.setHeightForWidth(spin_gauss->sizePolicy().hasHeightForWidth());
        spin_gauss->setSizePolicy(sizePolicy9);
        spin_gauss->setFont(font);
        spin_gauss->setMinimum(1);
        spin_gauss->setMaximum(99);

        horizontalLayout->addWidget(spin_gauss);

        label_pixels = new QLabel(image_properties_group);
        label_pixels->setObjectName(QStringLiteral("label_pixels"));
        sizePolicy9.setHeightForWidth(label_pixels->sizePolicy().hasHeightForWidth());
        label_pixels->setSizePolicy(sizePolicy9);
        label_pixels->setFont(font2);

        horizontalLayout->addWidget(label_pixels);


        verticalLayout_2->addLayout(horizontalLayout);


        smoothing_layout->addLayout(verticalLayout_2);

        horizontalSpacer_16 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        smoothing_layout->addItem(horizontalSpacer_16);


        verticalLayout_5->addLayout(smoothing_layout);

        reset_layout = new QHBoxLayout();
        reset_layout->setSpacing(6);
        reset_layout->setObjectName(QStringLiteral("reset_layout"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        reset_layout->addItem(horizontalSpacer_13);

        reset_image = new QPushButton(image_properties_group);
        reset_image->setObjectName(QStringLiteral("reset_image"));
        sizePolicy5.setHeightForWidth(reset_image->sizePolicy().hasHeightForWidth());
        reset_image->setSizePolicy(sizePolicy5);
        reset_image->setMinimumSize(QSize(230, 40));
        reset_image->setFont(font);

        reset_layout->addWidget(reset_image);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        reset_layout->addItem(horizontalSpacer_14);


        verticalLayout_5->addLayout(reset_layout);


        process_left_side->addWidget(image_properties_group);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        process_left_side->addItem(verticalSpacer_6);


        horizontalLayout_26->addLayout(process_left_side);

        horizontalSpacer_20 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_20);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_zoom_process = new QLabel(process_tab);
        label_zoom_process->setObjectName(QStringLiteral("label_zoom_process"));
        sizePolicy5.setHeightForWidth(label_zoom_process->sizePolicy().hasHeightForWidth());
        label_zoom_process->setSizePolicy(sizePolicy5);
        label_zoom_process->setMinimumSize(QSize(40, 20));
        label_zoom_process->setMaximumSize(QSize(30, 16777215));
        label_zoom_process->setFont(font);

        horizontalLayout_9->addWidget(label_zoom_process);

        zoom_setting_process = new QComboBox(process_tab);
        zoom_setting_process->setObjectName(QStringLiteral("zoom_setting_process"));
        zoom_setting_process->setEnabled(true);
        zoom_setting_process->setMinimumSize(QSize(70, 20));
        zoom_setting_process->setMaximumSize(QSize(70, 16777215));
        zoom_setting_process->setEditable(false);

        horizontalLayout_9->addWidget(zoom_setting_process);

        label_resolution_process = new QLabel(process_tab);
        label_resolution_process->setObjectName(QStringLiteral("label_resolution_process"));
        sizePolicy7.setHeightForWidth(label_resolution_process->sizePolicy().hasHeightForWidth());
        label_resolution_process->setSizePolicy(sizePolicy7);
        label_resolution_process->setMinimumSize(QSize(100, 20));
        label_resolution_process->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_9->addWidget(label_resolution_process);

        horizontalSpacer_28 = new QSpacerItem(638, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_28);


        verticalLayout->addLayout(horizontalLayout_9);

        scrollArea_Analyse = new QScrollArea(process_tab);
        scrollArea_Analyse->setObjectName(QStringLiteral("scrollArea_Analyse"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(scrollArea_Analyse->sizePolicy().hasHeightForWidth());
        scrollArea_Analyse->setSizePolicy(sizePolicy10);
        scrollArea_Analyse->setMinimumSize(QSize(1200, 900));
        scrollArea_Analyse->setLineWidth(2);
        scrollArea_Analyse->setWidgetResizable(true);
        scrollArea_Analyse->setAlignment(Qt::AlignCenter);
        analyse_scrollarea = new QWidget();
        analyse_scrollarea->setObjectName(QStringLiteral("analyse_scrollarea"));
        analyse_scrollarea->setGeometry(QRect(0, 0, 1198, 904));
        sizePolicy.setHeightForWidth(analyse_scrollarea->sizePolicy().hasHeightForWidth());
        analyse_scrollarea->setSizePolicy(sizePolicy);
        analyse_scrollarea->setMinimumSize(QSize(0, 0));
        analyse_scrollarea->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_21 = new QHBoxLayout(analyse_scrollarea);
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        analyse_display = new CVImageWidget(analyse_scrollarea);
        analyse_display->setObjectName(QStringLiteral("analyse_display"));
        sizePolicy3.setHeightForWidth(analyse_display->sizePolicy().hasHeightForWidth());
        analyse_display->setSizePolicy(sizePolicy3);
        analyse_display->setMinimumSize(QSize(0, 0));
        analyse_display->setBaseSize(QSize(0, 0));
        analyse_display->setAutoFillBackground(true);
        horizontalLayout_24 = new QHBoxLayout(analyse_display);
        horizontalLayout_24->setSpacing(0);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_21->addWidget(analyse_display);

        scrollArea_Analyse->setWidget(analyse_scrollarea);

        verticalLayout->addWidget(scrollArea_Analyse);


        horizontalLayout_26->addLayout(verticalLayout);

        evbl_tabs->addTab(process_tab, QString());
        anal_type_tab->raise();

        verticalLayout_8->addWidget(evbl_tabs);


        retranslateUi(eVBL);

        evbl_tabs->setCurrentIndex(0);
        anal_type_tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(eVBL);
    } // setupUi

    void retranslateUi(QWidget *eVBL)
    {
        eVBL->setWindowTitle(QApplication::translate("eVBL", "eVBL-beta     touch it... feel it...", 0));
        label_sauce->setText(QApplication::translate("eVBL", "Source", 0));
        label_gain->setText(QApplication::translate("eVBL", "Gain", 0));
        label_exposure->setText(QApplication::translate("eVBL", "Exposure", 0));
        capture_groupBox->setTitle(QApplication::translate("eVBL", "Capture", 0));
        capture_frame_button->setText(QApplication::translate("eVBL", "Single Capture", 0));
        multi_frame_button->setText(QApplication::translate("eVBL", "Multi Capture", 0));
        label_multishots->setText(QApplication::translate("eVBL", "Number of Multi Shots", 0));
        label_multishots2->setText(QApplication::translate("eVBL", "Multi Capture Status", 0));
        multishot_status->setText(QApplication::translate("eVBL", "--", 0));
        filename_groupBox->setTitle(QApplication::translate("eVBL", "File Information", 0));
        label_initials->setText(QApplication::translate("eVBL", "Initials", 0));
        info_initials->setText(QString());
        label_school->setText(QApplication::translate("eVBL", "School", 0));
        label_object->setText(QApplication::translate("eVBL", "Object", 0));
        combo_object->clear();
        combo_object->insertItems(0, QStringList()
         << QApplication::translate("eVBL", "Single Slit", 0)
         << QApplication::translate("eVBL", "Double Slit", 0)
         << QApplication::translate("eVBL", "Background", 0)
         << QApplication::translate("eVBL", "Unknown", 0)
        );
        label_distance->setText(QApplication::translate("eVBL", "Distance", 0));
        label_mm->setText(QApplication::translate("eVBL", "mm", 0));
        label_wavelength->setText(QApplication::translate("eVBL", "Wavelength", 0));
        combo_wavelength->clear();
        combo_wavelength->insertItems(0, QStringList()
         << QApplication::translate("eVBL", "532nm", 0)
         << QApplication::translate("eVBL", "635nm", 0)
        );
        label_objectnumber->setText(QApplication::translate("eVBL", "Object Number", 0));
        combo_objectnumber->clear();
        combo_objectnumber->insertItems(0, QStringList()
         << QApplication::translate("eVBL", "1", 0)
         << QApplication::translate("eVBL", "2", 0)
         << QApplication::translate("eVBL", "3", 0)
         << QApplication::translate("eVBL", "4", 0)
         << QApplication::translate("eVBL", "5", 0)
         << QApplication::translate("eVBL", "6", 0)
        );
        save_image_button->setText(QApplication::translate("eVBL", "Save Image", 0));
        label_zoom->setText(QApplication::translate("eVBL", "Zoom", 0));
        zoom_setting->clear();
        zoom_setting->insertItems(0, QStringList()
         << QApplication::translate("eVBL", "25%", 0)
         << QApplication::translate("eVBL", "33%", 0)
         << QApplication::translate("eVBL", "50%", 0)
         << QApplication::translate("eVBL", "75%", 0)
         << QApplication::translate("eVBL", "100%", 0)
         << QApplication::translate("eVBL", "150%", 0)
         << QApplication::translate("eVBL", "200%", 0)
         << QApplication::translate("eVBL", "Fit", 0)
        );
        zoom_setting->setCurrentText(QApplication::translate("eVBL", "25%", 0));
        label_resolution->setText(QApplication::translate("eVBL", "Size: n/a", 0));
        evbl_tabs->setTabText(evbl_tabs->indexOf(capture_tab), QApplication::translate("eVBL", "Capture", 0));
        imge_load_group->setTitle(QApplication::translate("eVBL", "Image Open/Save", 0));
        open_analysis_button->setText(QApplication::translate("eVBL", "Load Image", 0));
        label_loaded_file->setText(QApplication::translate("eVBL", "No File Loaded!", 0));
        background_button->setText(QApplication::translate("eVBL", "Load Background", 0));
        label_loaded_background->setText(QApplication::translate("eVBL", "No Background Loaded!", 0));
        label_background_warning->setText(QString());
        check_background->setText(QApplication::translate("eVBL", "Subtract background", 0));
        anal_group->setTitle(QApplication::translate("eVBL", "Analysis", 0));
        label_distance_measure->setText(QApplication::translate("eVBL", "Distance", 0));
        label_3->setText(QApplication::translate("eVBL", "Click 2 points on the image to measure the distance between.\n"
"Drag endpoints to fine tune.", 0));
        measured_distance->setText(QApplication::translate("eVBL", "--.-- mm", 0));
        anal_type_tab->setTabText(anal_type_tab->indexOf(length_tab), QApplication::translate("eVBL", "Length", 0));
        label_angle->setText(QApplication::translate("eVBL", "Angle", 0));
        angle_units_group->setTitle(QApplication::translate("eVBL", "Units", 0));
        radio_degrees->setText(QApplication::translate("eVBL", "Degrees", 0));
        radio_radians->setText(QApplication::translate("eVBL", "Radians", 0));
        label_4->setText(QApplication::translate("eVBL", "Click 3 points on the image to form angle to be measured.\n"
"Drag any of the 3 points to fine tune.", 0));
        angle_measurement->setText(QApplication::translate("eVBL", "--", 0));
        anal_type_tab->setTabText(anal_type_tab->indexOf(angle_tab), QApplication::translate("eVBL", "Angle", 0));
        label_rotate->setText(QApplication::translate("eVBL", "Rotate", 0));
        label_csvexport->setText(QApplication::translate("eVBL", "Export CSV to...", 0));
        file_button->setText(QApplication::translate("eVBL", "File", 0));
        clipboard_button->setText(QApplication::translate("eVBL", "Clipboard", 0));
        anal_type_tab->setTabText(anal_type_tab->indexOf(intensity_tab), QApplication::translate("eVBL", "Intensity", 0));
        label_2->setText(QApplication::translate("eVBL", "Click image to set centre of region to be cropped.\n"
"Grab centre of box to reposition.", 0));
        crop_info_label->setText(QApplication::translate("eVBL", "Save cropped version of image", 0));
        crop_button->setText(QApplication::translate("eVBL", "Save Cropped", 0));
        anal_type_tab->setTabText(anal_type_tab->indexOf(crop_tab), QApplication::translate("eVBL", "Crop", 0));
        label_line_properties->setText(QApplication::translate("eVBL", "Line Properties", 0));
        label_line_colourt->setText(QApplication::translate("eVBL", "Colour", 0));
        label_line_thickness->setText(QApplication::translate("eVBL", "Thickness", 0));
        combo_line_thickness->clear();
        combo_line_thickness->insertItems(0, QStringList()
         << QApplication::translate("eVBL", "1", 0)
         << QApplication::translate("eVBL", "2", 0)
         << QApplication::translate("eVBL", "3", 0)
         << QApplication::translate("eVBL", "4", 0)
         << QApplication::translate("eVBL", "5", 0)
        );
        label_line_pixels->setText(QApplication::translate("eVBL", "pixels", 0));
        image_properties_group->setTitle(QApplication::translate("eVBL", "Image Properties", 0));
        label_colours->setText(QApplication::translate("eVBL", "Colours", 0));
        check_invert->setText(QApplication::translate("eVBL", "Invert", 0));
        check_bw->setText(QApplication::translate("eVBL", "Black && White", 0));
        label_threshold->setText(QApplication::translate("eVBL", "Threshold", 0));
        label_lowpoint->setText(QApplication::translate("eVBL", "Low", 0));
        label_highpoint->setText(QApplication::translate("eVBL", "High", 0));
        label_smoothing->setText(QApplication::translate("eVBL", "Smoothing", 0));
        label_blur->setText(QApplication::translate("eVBL", "Gaussian Blur", 0));
        check_gaussian->setText(QApplication::translate("eVBL", "Enable", 0));
        label_pixels->setText(QApplication::translate("eVBL", "pixels", 0));
        reset_image->setText(QApplication::translate("eVBL", "Reset Image", 0));
        label_zoom_process->setText(QApplication::translate("eVBL", "Zoom", 0));
        zoom_setting_process->clear();
        zoom_setting_process->insertItems(0, QStringList()
         << QApplication::translate("eVBL", "25%", 0)
         << QApplication::translate("eVBL", "33%", 0)
         << QApplication::translate("eVBL", "50%", 0)
         << QApplication::translate("eVBL", "75%", 0)
         << QApplication::translate("eVBL", "100%", 0)
         << QApplication::translate("eVBL", "150%", 0)
         << QApplication::translate("eVBL", "200%", 0)
         << QApplication::translate("eVBL", "Fit", 0)
        );
        zoom_setting_process->setCurrentText(QApplication::translate("eVBL", "25%", 0));
        label_resolution_process->setText(QApplication::translate("eVBL", "Size: n/a", 0));
        evbl_tabs->setTabText(evbl_tabs->indexOf(process_tab), QApplication::translate("eVBL", "Process", 0));
    } // retranslateUi

};

namespace Ui {
    class eVBL: public Ui_eVBL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVBL_H
