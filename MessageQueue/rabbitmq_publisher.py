import pika, os, logging, sys

logging.basicConfig()

# Parse CLOUDAMQP_URL (fallback to RabbitMQ broker / localhost / cloudamqp)
url = os.environ.get('CLOUDAMQP_URL','amqps://tqzvyxix:oGh4wcsnvBrG2U5zzQBDgkcFH_ff8B8C@jackal.rmq.cloudamqp.com/tqzvyxix')
params = pika.URLParameters(url)
params.socket_timeout = 5 # Altera o timeout de 0.25s para 5s evitar problemas de conexoes lentas

# Estabelecendo a conexao, o canal e a fila
connection = pika.BlockingConnection(params)
channel = connection.channel()
channel.queue_declare(queue='pdfprocess_aula')

# Enviando uma mensagem (exchange=default, ....,...)
#channel.basic_publish(exchange='',routing_key='pdfprocess',body=sys.argv[1])

# Envio para o exchange 'professor'
channel.basic_publish(exchange='professor',routing_key='pdfprocess_aula',body=sys.argv[1])
print("[x] Mensagem enviada para o consumidor")

connection.close()
