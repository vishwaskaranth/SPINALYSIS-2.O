# SPINALYSIS

## Overview

**SPINALYSIS** is an intelligent gait analysis system that utilizes **flexible PCBs embedded with pressure sensors** inside shoes to monitor foot pressure distribution and walking patterns. The system comprises:

* **6 FlexiForce A401 sensors** per shoe (12 sensors in total)
* **ESP32 microcontrollers**
* **1S LiPo battery** with charging module
* **Flexible PCB** embedded beneath the shoe sole

The data collected from the sensors is transmitted wirelessly and visualized through a Python-based desktop application.

## Aim

The objective of this project is to **analyze foot pressure data** and **generate a comprehensive health report**, with a particular focus on evaluating the condition of the S1 and L1 spinal nerves.

## Team Members

* **Shashank B (Team leader & Testing Engineer)** — UI Designer | Head of Bio-Design | Medical Accuracy | Sensor Placement | Harware Testing
* **Shreesha Kumar M G (Lead Hardware Developer)** — Lead Developer | UI Designer | Electronics & PCB Designer | Hardware Integration
* **P. Vishwas Karanth (Lead Verification & Testing Engineer)** — Hardware-UI Integrator | PCB Verification & Hardware Testing | Sensor Placement | CAD Designer

## Mentors:

* **Ms. Nandini Maninarayana** — Research & Development Mentor
* **Dr. Ishwara Keerthi** — Medical Consultant

## System Architecture

### Hardware Setup

* Each shoe is equipped with an **ESP32-WROOM module**, functioning as a slave device to collect real-time pressure data.
* A master **ESP32-C3 dongle** is connected to the host computer via USB and acts as a Wi-Fi server.
* The slave ESP32 modules connect to the master via Wi-Fi and transmit sensor data upon request.
