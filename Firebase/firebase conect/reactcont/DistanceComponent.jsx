// DistanceComponent.js
import React, { useState, useEffect } from 'react';
import { database } from './firebase';
import { ref, onValue } from 'firebase/database';
import GoogleMapReact from 'google-map-react';

const AnyReactComponent = ({ text }) => <div>{text}</div>;

const DistanceComponent = () => {
  const [distances, setDistances] = useState([]);

  useEffect(() => {
    const distanceRef = ref(database, 'test');

    // Fetch existing distances
    const unsubscribe = onValue(distanceRef, (snapshot) => {
      const data = snapshot.val();
      const distanceList = data ? Object.values(data) : [];
      setDistances(distanceList);
    });

    // Cleanup subscription on unmount
    return () => unsubscribe();
  }, []);

  const defaultProps = {
    center: {
      lat: 6.714814953362556,
      lng:  80.78719703575784
    },
    zoom: 11
  };
  return (
    <div>
      <h2>Distance Is: </h2>
      <ul>
        {distances.map((distance, index) => (
          <li key={index}>  {distance}      cm         </li>
        ))}
      </ul>
      <div style={{ height: '100vh', width: '500px' }}>
      <GoogleMapReact
        bootstrapURLKeys={{ key: "" }}
        defaultCenter={defaultProps.center}
        defaultZoom={defaultProps.zoom}
      >
        <AnyReactComponent
          lat={6.714814953362556}
          lng={ 80.78719703575784}
          text="📍"
          
        />
      </GoogleMapReact>
    </div>
    </div>
  );
};

export default DistanceComponent;
