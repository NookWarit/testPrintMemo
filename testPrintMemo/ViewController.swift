//
//  ViewController.swift
//  testPrintMemo
//
//  Created by warittha on 6/8/2562 BE.
//  Copyright © 2562 warittha. All rights reserved.
//

import UIKit
import CoreBluetooth
import MemobirdSDK



struct Printer {
    var mac: String
    var peripheral: CBPeripheral
    var name: String {
        return "\(peripheral.name ?? "") - \(mac.components(separatedBy: ":").last ?? "")"
    }
    
    init(peripheral: CBPeripheral, mac: String) {
        self.mac = mac
        self.peripheral = peripheral
    }
}

class ViewController: UIViewController {
    let manager = MemobirdSDK.defaultManager()
    var peripheral: CBPeripheral?
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        manager?.start(withAppKey: "6b8e54a3242e4695968237dbe1780f59")
        manager?.delegate = self
    }
    
    @IBAction func Scan(_ sender: UIButton) {
        manager?.startScanMemobirdDevice()
        
//        let current = manager?.currentDeviceBluetoothState()
//        print(current!)
        
        
    }
    
    @IBAction func Print(_ sender: Any) {
       
    }
}

extension ViewController: MemobirdSDKDelegate {
    func didDiscoverMemobirdPeripheral(_ peripheral: CBPeripheral!, peripheralMacAddress macAddress: String!) {
//        print("macAddress\(macAddress)")
//        print(peripheral!)
        
        let devicesInfo = peripheral.description
//        peripheral.state = CBPeripheralState.connected
//        let devices = peripheral.canSendWriteWithoutResponse
//        let d = peripheral.customMirror
    
        print ("devicesInfo\(devicesInfo)")
        
//        manager?.currentDeviceBluetoothState()
//        devicesInfo.CBPeripheralManagerConnectionLatency
        
        
        self.peripheral = peripheral
        if let p = self.peripheral {
            manager?.printTask(withText: "1234567", memobirdPeripheral: p)
        }
        
        

        
    }
    
    func requestMemobirdPrintTaskFailed(_ error: MemobirdPrintTaskError) {
       print("error\(error)")
        
    }
}

