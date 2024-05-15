// firebase.js
import { initializeApp } from 'firebase/app';
import { getDatabase } from 'firebase/database';

const firebaseConfig = {
    apiKey: "AIzaSyBORz0upNkehcnguawpWMq5OOL0lLUwHwI",
    authDomain: "esp32-firebase-demo-f11b4.firebaseapp.com",
    databaseURL: "https://esp32-firebase-demo-f11b4-default-rtdb.asia-southeast1.firebasedatabase.app",
    projectId: "esp32-firebase-demo-f11b4",
    storageBucket: "esp32-firebase-demo-f11b4.appspot.com",
    messagingSenderId: "170488383023",
    appId: "1:170488383023:web:145cc905a978b4fd1968da"
  };
// Initialize Firebase
const app = initializeApp(firebaseConfig);

// Get a reference to the database service
const database = getDatabase(app);

export { database };