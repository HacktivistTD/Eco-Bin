import { useState } from 'react'

import './App.css'
import DistanceComponent from '../DistanceComponent'






function App() {
  const [count, setCount] = useState(0)

  return (
    <>
       <DistanceComponent/>
    </>
  )
}

export default App
