import * as SerialPort from 'serialport'
import * as dotenv from 'dotenv'

import { sequelize } from './services/sequelize'

dotenv.config()

const comPath = process.env.COMPATH
const baudRate = process.env.BAUDRATE

const setup = async () => {
  await sequelize
    .authenticate()
    .then(() => console.log('Database auth ok'))
    .catch(console.log)

  await sequelize
    .sync({ alter: true, force: false, logging: false })
    .then(() => console.log('Database sync ok'))
    .catch(console.log)

  const port = new SerialPort(comPath, { baudRate: parseInt(baudRate) })

  port.addListener('data', (chunk: Buffer) => {
    console.log(chunk.toString('utf-8'))
  })

  console.log(`Listening to ${comPath}, baud rate ${baudRate}`)
}

setup()
